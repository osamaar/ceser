#include <stdint.h>
#include <gtest/gtest.h>

extern "C" {
    #include <ceser.h>
}

class ReadIntTest : public ::testing::Test {
protected:
    const unsigned char buf[8] = {
        0xaa, 0xbb, 0xcc, 0xdd, 0x11, 0x22, 0x33, 0x44
    };
};

TEST_F(ReadIntTest, ReadBigEndianInt) {
    uint8_t u8 = read_be_u8(buf, 0);
    uint16_t u16 = read_be_u16(buf, 0);
    uint32_t u32 = read_be_u32(buf, 0);
    uint64_t u64 = read_be_u64(buf, 0);

    int8_t i8 = read_be_i8(buf, 0);
    int16_t i16 = read_be_i16(buf, 0);
    int32_t i32 = read_be_i32(buf, 0);
    int64_t i64 = read_be_i64(buf, 0);

    EXPECT_EQ(u8, 0xaa);
    EXPECT_EQ(u16, 0xaabb);
    EXPECT_EQ(u32, 0xaabbccdd);
    EXPECT_EQ(u64, 0xaabbccdd11223344);

    EXPECT_EQ(i8, (int8_t) 0xaa);
    EXPECT_EQ(i16, (int16_t) 0xaabb);
    EXPECT_EQ(i32, (int32_t) 0xaabbccdd);
    EXPECT_EQ(i64, (int64_t) 0xaabbccdd11223344);
}

TEST_F(ReadIntTest, ReadLittleEndianInt) {
    uint8_t u8 = read_le_u8(buf, 0);
    uint16_t u16 = read_le_u16(buf, 0);
    uint32_t u32 = read_le_u32(buf, 0);
    uint64_t u64 = read_le_u64(buf, 0);

    int8_t i8 = read_le_i8(buf, 0);
    int16_t i16 = read_le_i16(buf, 0);
    int32_t i32 = read_le_i32(buf, 0);
    int64_t i64 = read_le_i64(buf, 0);

    EXPECT_EQ(u8, 0xaa);
    EXPECT_EQ(u16, 0xbbaa);
    EXPECT_EQ(u32, 0xddccbbaa);
    EXPECT_EQ(u64, 0x44332211ddccbbaa);

    EXPECT_EQ(i8, (int8_t) 0xaa);
    EXPECT_EQ(i16, (int16_t) 0xbbaa);
    EXPECT_EQ(i32, (int32_t) 0xddccbbaa);
    EXPECT_EQ(i64, (int64_t) 0x44332211ddccbbaa);
}

class WriteIntTest : public ::testing::Test {
protected:
    unsigned char buf[16];

    void SetUp() override {
        memset(buf, 0, 16);
    }
};

TEST_F(WriteIntTest, WriteBigEndianU8) {
    int ret = write_be_u8(0xaa, buf);
    EXPECT_EQ(ret, 1);
    EXPECT_EQ(buf[0], 0xaa);
}

TEST_F(WriteIntTest, WriteBigEndianU16) {
    int ret = write_be_u16(0xaabb, buf);
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
}

TEST_F(WriteIntTest, WriteBigEndianU32) {
    int ret = write_be_u32(0xaabbccdd, buf);
    EXPECT_EQ(ret, 4);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
    EXPECT_EQ(buf[2], 0xcc);
    EXPECT_EQ(buf[3], 0xdd);
}

TEST_F(WriteIntTest, WriteBigEndianU64) {
    int ret = write_be_u64(0xaabbccdd11223344, buf);
    EXPECT_EQ(ret, 8);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
    EXPECT_EQ(buf[2], 0xcc);
    EXPECT_EQ(buf[3], 0xdd);
    EXPECT_EQ(buf[4], 0x11);
    EXPECT_EQ(buf[5], 0x22);
    EXPECT_EQ(buf[6], 0x33);
    EXPECT_EQ(buf[7], 0x44);
}

TEST_F(WriteIntTest, WriteBigEndianI8) {
    int ret = write_be_i8(0xaa, buf);
    EXPECT_EQ(ret, 1);
    EXPECT_EQ(buf[0], 0xaa);
}

TEST_F(WriteIntTest, WriteBigEndianI16) {
    int ret = write_be_i16(0xaabb, buf);
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
}

TEST_F(WriteIntTest, WriteBigEndianI32) {
    int ret = write_be_i32(0xaabbccdd, buf);
    EXPECT_EQ(ret, 4);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
    EXPECT_EQ(buf[2], 0xcc);
    EXPECT_EQ(buf[3], 0xdd);
}

TEST_F(WriteIntTest, WriteBigEndianI64) {
    int ret = write_be_i64(0xaabbccdd11223344, buf);
    EXPECT_EQ(ret, 8);
    EXPECT_EQ(buf[0], 0xaa);
    EXPECT_EQ(buf[1], 0xbb);
    EXPECT_EQ(buf[2], 0xcc);
    EXPECT_EQ(buf[3], 0xdd);
    EXPECT_EQ(buf[4], 0x11);
    EXPECT_EQ(buf[5], 0x22);
    EXPECT_EQ(buf[6], 0x33);
    EXPECT_EQ(buf[7], 0x44);
}

TEST_F(WriteIntTest, WriteLittleEndianU8) {
    int ret = write_le_u8(0xaa, buf);
    EXPECT_EQ(ret, 1);
    EXPECT_EQ(buf[0], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianU16) {
    int ret = write_le_u16(0xaabb, buf);
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(buf[0], 0xbb);
    EXPECT_EQ(buf[1], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianU32) {
    int ret = write_le_u32(0xaabbccdd, buf);
    EXPECT_EQ(ret, 4);
    EXPECT_EQ(buf[0], 0xdd);
    EXPECT_EQ(buf[1], 0xcc);
    EXPECT_EQ(buf[2], 0xbb);
    EXPECT_EQ(buf[3], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianU64) {
    int ret = write_le_u64(0xaabbccdd11223344, buf);
    EXPECT_EQ(ret, 8);
    EXPECT_EQ(buf[0], 0x44);
    EXPECT_EQ(buf[1], 0x33);
    EXPECT_EQ(buf[2], 0x22);
    EXPECT_EQ(buf[3], 0x11);
    EXPECT_EQ(buf[4], 0xdd);
    EXPECT_EQ(buf[5], 0xcc);
    EXPECT_EQ(buf[6], 0xbb);
    EXPECT_EQ(buf[7], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianI8) {
    int ret = write_le_i8(0xaa, buf);
    EXPECT_EQ(ret, 1);
    EXPECT_EQ(buf[0], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianI16) {
    int ret = write_le_i16(0xaabb, buf);
    EXPECT_EQ(ret, 2);
    EXPECT_EQ(buf[0], 0xbb);
    EXPECT_EQ(buf[1], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianI32) {
    int ret = write_le_i32(0xaabbccdd, buf);
    EXPECT_EQ(ret, 4);
    EXPECT_EQ(buf[0], 0xdd);
    EXPECT_EQ(buf[1], 0xcc);
    EXPECT_EQ(buf[2], 0xbb);
    EXPECT_EQ(buf[3], 0xaa);
}

TEST_F(WriteIntTest, WriteLittleEndianI64) {
    int ret = write_le_i64(0xaabbccdd11223344, buf);
    EXPECT_EQ(ret, 8);
    EXPECT_EQ(buf[0], 0x44);
    EXPECT_EQ(buf[1], 0x33);
    EXPECT_EQ(buf[2], 0x22);
    EXPECT_EQ(buf[3], 0x11);
    EXPECT_EQ(buf[4], 0xdd);
    EXPECT_EQ(buf[5], 0xcc);
    EXPECT_EQ(buf[6], 0xbb);
    EXPECT_EQ(buf[7], 0xaa);
}

class FloatsTest : public ::testing::Test {
protected:
    unsigned char buf[16];
    const float f32_in = 3.14159265358979323846;
    const double f64_in = 3.14159265358979323846;

    void SetUp() override {
        memset(buf, 0, 16);
    }
};

TEST_F(FloatsTest, ReadWriteBEF32) {
    write_be_f32(f32_in, buf);
    float f32_out = read_be_f32(buf, 0);
    EXPECT_EQ(f32_in, f32_out);
}

TEST_F(FloatsTest, ReadWriteBEF64) {
    write_be_f64(f64_in, buf);
    double f64_out = read_be_f64(buf, 0);
    EXPECT_EQ(f64_in, f64_out);
}
