#include <stdint.h>
#include <memory.h>
#include <ceser.h>
#include "float_ieee754.h"

/////////////////////////////////////////////////
// Big Endian Read
uint8_t read_be_u8(const unsigned char *buffer, size_t offset) {
    return *(buffer + offset);
}

uint16_t read_be_u16(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint16_t out = 0;
    out |= *p++ << 8;
    out |= *p++;
    return out;
}

uint32_t read_be_u32(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint32_t out = 0;
    out |= *p++ << 24;
    out |= *p++ << 16;
    out |= *p++ << 8;
    out |= *p++;
    return out;
}

uint64_t read_be_u64(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint64_t out = 0;
    out |= (uint64_t) *p++ << 56;
    out |= (uint64_t) *p++ << 48;
    out |= (uint64_t) *p++ << 40;
    out |= (uint64_t) *p++ << 32;
    out |= (uint64_t) *p++ << 24;
    out |= (uint64_t) *p++ << 16;
    out |= (uint64_t) *p++ << 8;
    out |= (uint64_t) *p++;
    return out;
}

int8_t read_be_i8(const unsigned char *buffer, size_t offset) {
    int8_t out;
    memcpy(&out, buffer + offset, 1);
    return out;
}

int16_t read_be_i16(const unsigned char *buffer, size_t offset) {
    int16_t out;
    uint16_t u = read_be_u16(buffer, offset);
    memcpy(&out, &u, 2);
    return out;
}

int32_t read_be_i32(const unsigned char *buffer, size_t offset) {
    int32_t out;
    uint32_t u = read_be_u32(buffer, offset);
    memcpy(&out, &u, 4);
    return out;
}

int64_t read_be_i64(const unsigned char *buffer, size_t offset) {
    int64_t out;
    uint64_t u = read_be_u64(buffer, offset);
    memcpy(&out, &u, 8);
    return out;
}

// Big Endian Write
int write_be_u8(uint8_t value, unsigned char *buffer) {
    *buffer = value;
    return 1;
}

int write_be_u16(uint16_t value, unsigned char *buffer) {
    *buffer++ = (value >> 8) & 0xff;
    *buffer++ = value & 0xff;
    return 2;
}

int write_be_u32(uint32_t value, unsigned char *buffer) {
    *buffer++ = (value >> 24) & 0xff;
    *buffer++ = (value >> 16) & 0xff;
    *buffer++ = (value >> 8) & 0xff;
    *buffer++ = value & 0xff;
    return 4;
}

int write_be_u64(uint64_t value, unsigned char *buffer) {
    *buffer++ = (value >> 56) & 0xff;
    *buffer++ = (value >> 48) & 0xff;
    *buffer++ = (value >> 40) & 0xff;
    *buffer++ = (value >> 32) & 0xff;
    *buffer++ = (value >> 24) & 0xff;
    *buffer++ = (value >> 16) & 0xff;
    *buffer++ = (value >> 8) & 0xff;
    *buffer++ = value & 0xff;
    return 8;
}

int write_be_i8(int8_t value, unsigned char *buffer) {
    uint8_t u;
    memcpy(&u, &value, 1);
    return write_be_u8(u, buffer);
}

int write_be_i16(int16_t value, unsigned char *buffer) {
    uint16_t u;
    memcpy(&u, &value, 2);
    return write_be_u16(u, buffer);
}

int write_be_i32(int32_t value, unsigned char *buffer) {
    uint32_t u;
    memcpy(&u, &value, 4);
    return write_be_u32(u, buffer);
}

int write_be_i64(int64_t value, unsigned char *buffer) {
    uint64_t u;
    memcpy(&u, &value, 8);
    return write_be_u64(u, buffer);
}


/////////////////////////////////////////////////
// Little Endian Read
uint8_t read_le_u8(const unsigned char *buffer, size_t offset) {
    return *(buffer + offset);
}

uint16_t read_le_u16(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint16_t out = *p++;
    out |= *p++ << 8;
    return out;
}

uint32_t read_le_u32(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint32_t out = *p++;
    out |= *p++ << 8;
    out |= *p++ << 16;
    out |= *p++ << 24;
    return out;
}

uint64_t read_le_u64(const unsigned char *buffer, size_t offset) {
    const unsigned char *p = buffer + offset;
    uint64_t out = (uint64_t) *p++;
    out |= (uint64_t) *p++ << 8;
    out |= (uint64_t) *p++ << 16;
    out |= (uint64_t) *p++ << 24;
    out |= (uint64_t) *p++ << 32;
    out |= (uint64_t) *p++ << 40;
    out |= (uint64_t) *p++ << 48;
    out |= (uint64_t) *p++ << 56;
    return out;
}

int8_t read_le_i8(const unsigned char *buffer, size_t offset) {
    int8_t out;
    memcpy(&out, buffer + offset, 1);
    return out;
}

int16_t read_le_i16(const unsigned char *buffer, size_t offset) {
    int16_t out;
    uint16_t u = read_le_u16(buffer, offset);
    memcpy(&out, &u, 2);
    return out;
}

int32_t read_le_i32(const unsigned char *buffer, size_t offset) {
    int32_t out;
    uint32_t u = read_le_u32(buffer, offset);
    memcpy(&out, &u, 4);
    return out;
}

int64_t read_le_i64(const unsigned char *buffer, size_t offset) {
    int64_t out;
    uint64_t u = read_le_u64(buffer, offset);
    memcpy(&out, &u, 8);
    return out;
}

// Little Endian Write
int write_le_u8(uint8_t value, unsigned char *buffer) {
    *buffer = value;
    return 1;
}

int write_le_u16(uint16_t value, unsigned char *buffer) {
    *buffer++ = value & 0xff;
    *buffer++ = (value >> 8) & 0xff;
    return 2;
}

int write_le_u32(uint32_t value, unsigned char *buffer) {
    *buffer++ = value & 0xff;
    *buffer++ = (value >> 8) & 0xff;
    *buffer++ = (value >> 16) & 0xff;
    *buffer++ = (value >> 24) & 0xff;
    return 4;
}

int write_le_u64(uint64_t value, unsigned char *buffer) {
    *buffer++ = value & 0xff;
    *buffer++ = (value >> 8) & 0xff;
    *buffer++ = (value >> 16) & 0xff;
    *buffer++ = (value >> 24) & 0xff;
    *buffer++ = (value >> 32) & 0xff;
    *buffer++ = (value >> 40) & 0xff;
    *buffer++ = (value >> 48) & 0xff;
    *buffer++ = (value >> 56) & 0xff;
    return 8;
}

int write_le_i8(int8_t value, unsigned char *buffer) {
    uint8_t u;
    memcpy(&u, &value, 1);
    return write_le_u8(u, buffer);
}

int write_le_i16(int16_t value, unsigned char *buffer) {
    uint16_t u;
    memcpy(&u, &value, 2);
    return write_le_u16(u, buffer);
}

int write_le_i32(int32_t value, unsigned char *buffer) {
    uint32_t u;
    memcpy(&u, &value, 4);
    return write_le_u32(u, buffer);
}

int write_le_i64(int64_t value, unsigned char *buffer) {
    uint64_t u;
    memcpy(&u, &value, 8);
    return write_le_u64(u, buffer);
}

// Floating Point Types
// TODO: Implement float and double
float read_be_f32(const unsigned char *buffer, size_t offset) {
    uint32_t u = read_be_u32(buffer, offset);
    return u32_to_f32(u);
}

double read_be_f64(const unsigned char *buffer, size_t offset) {
    uint64_t u = read_be_u64(buffer, offset);
    return u64_to_f64(u);
}

int write_be_f32(float value, unsigned char *buffer) {
    uint32_t u = f32_to_u32(value);
    return write_be_u32(u, buffer);
}

int write_be_f64(double value, unsigned char *buffer) {
    uint64_t u = f64_to_u64(value);
    return write_be_u64(u, buffer);
}

float read_le_f32(const unsigned char *buffer, size_t offset) {
    uint32_t u = read_le_u32(buffer, offset);
    return u32_to_f32(u);
}

double read_le_f64(const unsigned char *buffer, size_t offset) {
    uint64_t u = read_le_u64(buffer, offset);
    return u64_to_f64(u);
}

int write_le_f32(float value, unsigned char *buffer) {
    uint32_t u = f32_to_u32(value);
    return write_le_u32(u, buffer);
}

int write_le_f64(double value, unsigned char *buffer) {
    uint64_t u = f64_to_u64(value);
    return write_le_u64(u, buffer);
}