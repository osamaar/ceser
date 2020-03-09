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
    unsigned char buf[8];

    void SetUp() override {
        memset(buf, 0, 8);
    }
};

TEST_F(WriteIntTest, WriteBigEndian) {
}

TEST_F(WriteIntTest, WriteLittleEndian) {
}