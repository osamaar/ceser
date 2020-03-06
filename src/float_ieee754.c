#include <stdint.h>
#include <math.h>
#include "float_ieee754.h"

///////////////////////////////////////////////////
// FP64
#define FP64_SIGN_BIT 1
#define FP64_EXPONENT_BIT 11
#define FP64_FRACTION_BIT 52

#define FP64_MAX_EXPONENT 1023
#define FP64_MIN_EXPONENT (-1022)

#define FP64_EXPONENT_BIAS 1023

#define FP64_SIGNBIT_MASK 1ULL
#define FP64_EXPONENT_MASK ((1ULL << FP64_EXPONENT_BIT) - 1)
#define FP64_FRACTION_MASK ((1ULL << FP64_FRACTION_BIT) - 1)

#define FP64_FRACTION_SHIFT 0
#define FP64_EXPONENT_SHIFT (FP64_FRACTION_SHIFT + FP64_FRACTION_BIT)
#define FP64_SIGNBIT_SHIFT (FP64_EXPONENT_SHIFT + FP64_EXPONENT_BIT)

///////////////////////////////////////////////////
// FP32
#define FP32_SIGN_BIT 1
#define FP32_EXPONENT_BIT 8
#define FP32_FRACTION_BIT 23

#define FP32_MAX_EXPONENT 127
#define FP32_MIN_EXPONENT (-126)

#define FP32_EXPONENT_BIAS 127

#define FP32_SIGNBIT_MASK 1ULL
#define FP32_FRACTION_MASK ((1ULL << FP32_FRACTION_BIT) - 1)
#define FP32_EXPONENT_MASK ((1ULL << FP32_EXPONENT_BIT) - 1)

#define FP32_FRACTION_SHIFT 0
#define FP32_EXPONENT_SHIFT (FP32_FRACTION_SHIFT + FP32_FRACTION_BIT)
#define FP32_SIGNBIT_SHIFT (FP32_EXPONENT_SHIFT + FP32_EXPONENT_BIT)

typedef struct fp64_s {
    uint64_t    fraction;   /* 52 bits */
    uint16_t    exponent;   /* 11 bits */
    uint8_t     sign_bit;   /* 1 bit */
} fp64;

typedef struct fp32_s {
    uint32_t    fraction;   /* 23 bits */
    uint8_t     exponent;   /* 8 bits */
    uint8_t     sign_bit;   /* 1 bit */
} fp32;

////////////////////////////////////////////////////
// Read

float u32_to_f32(uint32_t u) {
    // Copied and modified from hcl_u64_to_f64() below...
    // TODO: combine implementations of floating point types decoding.
    fp32 fp;
    int32_t exp;

    fp.fraction = (u >> FP32_FRACTION_SHIFT) & FP32_FRACTION_MASK;
    fp.exponent = (u >> FP32_EXPONENT_SHIFT) & FP32_EXPONENT_MASK;
    fp.sign_bit = (u >> FP32_SIGNBIT_SHIFT) & FP32_SIGNBIT_MASK;

    int sign = fp.sign_bit? -1 : 1;

    switch (fp.exponent) {
        case 0:
            if (fp.fraction == 0) return fp.sign_bit? -0.0 : 0.0;
            // subnormal value.
            exp = -FP32_EXPONENT_BIAS;
            return sign * ldexpf(fp.fraction , exp - FP32_FRACTION_BIT + 1);
            break;
        case FP32_EXPONENT_MASK:
            return NAN;     // remember NAN != NAN
            break;
        default:
            // normalized value. restore implicit 1.
            fp.fraction |= FP32_FRACTION_MASK + 1;
            exp = (int32_t)fp.exponent - FP32_EXPONENT_BIAS;
            return sign * ldexpf(fp.fraction, exp - FP32_FRACTION_BIT);
            break;
    }

    return NAN;
}

double u64_to_f64(uint64_t u) {
    fp64 fp;
    int32_t exp;

    fp.fraction = (u >> FP64_FRACTION_SHIFT) & FP64_FRACTION_MASK;
    fp.exponent = (u >> FP64_EXPONENT_SHIFT) & FP64_EXPONENT_MASK;
    fp.sign_bit = (u >> FP64_SIGNBIT_SHIFT) & FP64_SIGNBIT_MASK;

    int sign = fp.sign_bit? -1 : 1;

    switch (fp.exponent) {
        case 0:
            if (fp.fraction == 0) return fp.sign_bit? -0.0 : 0.0;
            // subnormal value.
            exp = -FP64_EXPONENT_BIAS;
            return sign * ldexp(fp.fraction , exp - FP64_FRACTION_BIT + 1);
            break;
        case FP64_EXPONENT_MASK:
            return NAN;     // remember NAN != NAN
            break;
        default:
            // normalized value. restore implicit 1.
            fp.fraction |= FP64_FRACTION_MASK + 1;
            exp = (int32_t)fp.exponent - FP64_EXPONENT_BIAS;
            return sign * ldexp(fp.fraction, exp - FP64_FRACTION_BIT);
            break;
    }

    return NAN;
}

////////////////////////////////////////////////////
// Write

uint32_t f32_to_u32(float f) {
    // Copied and modified from hcl_f64_to_u64() below...
    // TODO: combine implementations of floating point types encoding.
    fp32 fp;
    float fract;
    int32_t exp;
    uint32_t result;

    switch (fpclassify(f)) {
        case FP_ZERO:
            fp.sign_bit = signbit(f);
            fp.fraction = 0;
            fp.exponent = 0;
            break;

        case FP_INFINITE:
            fp.sign_bit = signbit(f);
            fp.fraction = 0;
            fp.exponent = FP32_EXPONENT_MASK;
            break;

        case FP_NAN:
            fp.sign_bit = 0;
            fp.fraction = 1;
            fp.exponent = FP32_EXPONENT_MASK;
            break;

        case FP_SUBNORMAL:
        case FP_NORMAL:
            fp.sign_bit = signbit(f);
            fract = fabs(frexpf(f, &exp));

            // compensate for implicit 1.
            exp -= 1;
            fract = ldexpf(fract, 1);

            if (exp > FP32_MAX_EXPONENT) {
                // use +/- infinity for out of bounds numbers.
                fp.fraction = 0;
                fp.exponent = FP32_EXPONENT_MASK;
            } else if (exp < FP32_MIN_EXPONENT) {
                // -1 shift to undo the implicit compensation.
                fp.fraction = trunc(ldexpf(fract, FP32_FRACTION_BIT - 1));
                fp.fraction >>= -(exp + FP32_EXPONENT_BIAS);
                fp.exponent = 0;
            } else {
                fp.fraction = trunc(ldexpf(fract, FP32_FRACTION_BIT));
                fp.exponent = exp + FP32_EXPONENT_BIAS;
            }

            break;
    }

    result =  (fp.fraction & FP32_FRACTION_MASK) << FP32_FRACTION_SHIFT;
    result |= (fp.exponent & FP32_EXPONENT_MASK) << FP32_EXPONENT_SHIFT;
    result |= (fp.sign_bit & FP32_SIGNBIT_MASK) << FP32_SIGNBIT_SHIFT;

    return result;
}

uint64_t f64_to_u64(double d) {
    fp64 fp;
    double fract;
    int32_t exp;
    uint64_t result;

    switch (fpclassify(d)) {
        case FP_ZERO:
            fp.sign_bit = signbit(d);
            fp.fraction = 0;
            fp.exponent = 0;
            break;

        case FP_INFINITE:
            fp.sign_bit = signbit(d);
            fp.fraction = 0;
            fp.exponent = FP64_EXPONENT_MASK;
            break;

        case FP_NAN:
            fp.sign_bit = 0;
            fp.fraction = 1;
            fp.exponent = FP64_EXPONENT_MASK;
            break;

        case FP_SUBNORMAL:
        case FP_NORMAL:
            fp.sign_bit = signbit(d);
            fract = fabs(frexp(d, &exp));

            // compensate for implicit 1.
            exp -= 1;
            fract = ldexp(fract, 1);

            if (exp > FP64_MAX_EXPONENT) {
                // use +/- infinity for out of bounds numbers.
                fp.fraction = 0;
                fp.exponent = FP64_EXPONENT_MASK;
            } else if (exp < FP64_MIN_EXPONENT) {
                // -1 shift to undo the implicit compensation.
                fp.fraction = trunc(ldexp(fract, FP64_FRACTION_BIT - 1));
                fp.fraction >>= -(exp + FP64_EXPONENT_BIAS);
                fp.exponent = 0;
            } else {
                fp.fraction = trunc(ldexp(fract, FP64_FRACTION_BIT));
                fp.exponent = exp + FP64_EXPONENT_BIAS;
            }

            break;
    }

    result =  (fp.fraction & FP64_FRACTION_MASK) << FP64_FRACTION_SHIFT;
    result |= (fp.exponent & FP64_EXPONENT_MASK) << FP64_EXPONENT_SHIFT;
    result |= (fp.sign_bit & FP64_SIGNBIT_MASK) << FP64_SIGNBIT_SHIFT;

    return result;
}
