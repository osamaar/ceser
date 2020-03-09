#include <stdint.h>
#include <gtest/gtest.h>

extern "C" {
    #include <ceser.h>
}

class ReadTest : public ::testing::Test {
protected:
    const unsigned char buf[8] = {
        0xaa, 0xbb, 0xcc, 0xdd, 0x11, 0x22, 0x33, 0x44
    };
};

TEST_F(ReadTest, ReadBigEndian) {
    uint8_t u8 = read_be_u8(buf, 0);
    uint16_t u16 = read_be_u16(buf, 0);
    uint32_t u32 = read_be_u32(buf, 0);
    uint64_t u64 = read_be_u64(buf, 0);

    EXPECT_EQ(u8, 0xaa);
    EXPECT_EQ(u16, 0xaabb);
    EXPECT_EQ(u32, 0xaabbccdd);
    EXPECT_EQ(u64, 0xaabbccdd11223344);
}

TEST_F(ReadTest, ReadLittleEndian) {
    uint8_t u8 = read_le_u8(buf, 0);
    uint16_t u16 = read_le_u16(buf, 0);
    uint32_t u32 = read_le_u32(buf, 0);
    uint64_t u64 = read_le_u64(buf, 0);

    EXPECT_EQ(u8, 0xaa);
    EXPECT_EQ(u16, 0xbbaa);
    EXPECT_EQ(u32, 0xddccbbaa);
    EXPECT_EQ(u64, 0x44332211ddccbbaa);
}