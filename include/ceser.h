#pragma once

#include <stdint.h>
#include <ceser.h>

// Big Endian
uint8_t read_be_u8(unsigned char *buffer, size_t offset);
uint16_t read_be_u16(unsigned char *buffer, size_t offset);
uint32_t read_be_u32(unsigned char *buffer, size_t offset);
uint64_t read_be_u64(unsigned char *buffer, size_t offset);

int8_t read_be_i8(unsigned char *buffer, size_t offset);
int16_t read_be_i16(unsigned char *buffer, size_t offset);
int32_t read_be_i32(unsigned char *buffer, size_t offset);
int64_t read_be_i64(unsigned char *buffer, size_t offset);

int write_be_u8(uint8_t value, unsigned char *buffer);
int write_be_u16(uint16_t value, unsigned char *buffer);
int write_be_u32(uint32_t value, unsigned char *buffer);
int write_be_u64(uint64_t value, unsigned char *buffer);

int write_be_i8(int8_t value, unsigned char *buffer);
int write_be_i16(int16_t value, unsigned char *buffer);
int write_be_i32(int32_t value, unsigned char *buffer);
int write_be_i64(int64_t value, unsigned char *buffer);

// Little Endian
uint8_t read_le_u8(unsigned char *buffer, size_t offset);
uint16_t read_le_u16(unsigned char *buffer, size_t offset);
uint32_t read_le_u32(unsigned char *buffer, size_t offset);
uint64_t read_le_u64(unsigned char *buffer, size_t offset);

int8_t read_le_i8(unsigned char *buffer, size_t offset);
int16_t read_le_i16(unsigned char *buffer, size_t offset);
int32_t read_le_i32(unsigned char *buffer, size_t offset);
int64_t read_le_i64(unsigned char *buffer, size_t offset);

int write_le_u8(uint8_t value, unsigned char *buffer);
int write_le_u16(uint16_t value, unsigned char *buffer);
int write_le_u32(uint32_t value, unsigned char *buffer);
int write_le_u64(uint64_t value, unsigned char *buffer);

int write_le_i8(int8_t value, unsigned char *buffer);
int write_le_i16(int16_t value, unsigned char *buffer);
int write_le_i32(int32_t value, unsigned char *buffer);
int write_le_i64(int64_t value, unsigned char *buffer);
