#include <stdio.h>
#include <memory.h>
#include <ceser.h>

int main() {
    printf("cesr example...");

    uint32_t u32_in = 0xaabbccdd;
    unsigned char arr[16];
    write_be_u32(u32_in, arr);

    // uint32_t u32_out;
    // memcpy(&u32_out, arr, 4);

    uint32_t u32_out = read_be_u32(arr, 0);

    printf("BE u32 in: 0x%08x\n", u32_in);
    printf("BE u32 out: 0x%08x\n", u32_out);

    return 0;
}