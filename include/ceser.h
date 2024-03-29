#pragma once

#include <stdint.h>
#include <ceser.h>

uint8_t read_u8(const unsigned char *buffer, size_t offset);
int8_t read_i8(const unsigned char *buffer, size_t offset);
int write_u8(uint8_t value, unsigned char *buffer);
int write_i8(int8_t value, unsigned char *buffer);

// Big Endian
uint16_t read_be_u16(const unsigned char *buffer, size_t offset);
uint32_t read_be_u32(const unsigned char *buffer, size_t offset);
uint64_t read_be_u64(const unsigned char *buffer, size_t offset);

int16_t read_be_i16(const unsigned char *buffer, size_t offset);
int32_t read_be_i32(const unsigned char *buffer, size_t offset);
int64_t read_be_i64(const unsigned char *buffer, size_t offset);

int write_be_u16(uint16_t value, unsigned char *buffer);
int write_be_u32(uint32_t value, unsigned char *buffer);
int write_be_u64(uint64_t value, unsigned char *buffer);

int write_be_i16(int16_t value, unsigned char *buffer);
int write_be_i32(int32_t value, unsigned char *buffer);
int write_be_i64(int64_t value, unsigned char *buffer);

float read_be_f32(const unsigned char *buffer, size_t offset);
double read_be_f64(const unsigned char *buffer, size_t offset);

int write_be_f32(float value, unsigned char *buffer);
int write_be_f64(double value, unsigned char *buffer);

// Little Endian
uint16_t read_le_u16(const unsigned char *buffer, size_t offset);
uint32_t read_le_u32(const unsigned char *buffer, size_t offset);
uint64_t read_le_u64(const unsigned char *buffer, size_t offset);

int16_t read_le_i16(const unsigned char *buffer, size_t offset);
int32_t read_le_i32(const unsigned char *buffer, size_t offset);
int64_t read_le_i64(const unsigned char *buffer, size_t offset);

int write_le_u16(uint16_t value, unsigned char *buffer);
int write_le_u32(uint32_t value, unsigned char *buffer);
int write_le_u64(uint64_t value, unsigned char *buffer);

int write_le_i16(int16_t value, unsigned char *buffer);
int write_le_i32(int32_t value, unsigned char *buffer);
int write_le_i64(int64_t value, unsigned char *buffer);

float read_le_f32(const unsigned char *buffer, size_t offset);
double read_le_f64(const unsigned char *buffer, size_t offset);

int write_le_f32(float value, unsigned char *buffer);
int write_le_f64(double value, unsigned char *buffer);