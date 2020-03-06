#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <float.h>
#include <ceser.h>

int main() {
    printf("cesr example...\n");
    unsigned char buf[16];

    ///////////////////////////////////////////
    memset(buf, 0, 16);
    uint32_t u32_in = 0xaabbccdd;
    write_be_u32(u32_in, buf);
    uint32_t u32_out = read_be_u32(buf, 0);

    printf("\n");
    printf("BE u32 in: 0x%08x\n", u32_in);
    printf("BE u32 out: 0x%08x\n", u32_out);
    assert(u32_out == u32_in);
    printf("ASSERT OK: u32 out == u32 in\n");

    ///////////////////////////////////////////
    memset(buf, 0, 16);
    // double f64_in = acos(-1.0);
    double f64_in = 3.14159265358979323846;
    write_be_f64(f64_in, buf);
    double f64_out = read_be_f64(buf, 0);
    
    printf("\n");
    printf("BE f64 in: %.15f\n", f64_in);
    printf("BE f64 out: %.15f\n", f64_out);
    assert(f64_out == f64_in);
    printf("ASSERT OK: f64 out == f64 in\n");

    return 0;
}