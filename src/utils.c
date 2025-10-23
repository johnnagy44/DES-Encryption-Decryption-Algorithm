#include "../inc/utils.h"

uint8_t get_bit(uint64_t data, int des_pos)
{
    return (data >> (64 - des_pos)) & 1ULL;
}

void set_bit(uint64_t *data, int des_pos, uint8_t value)
{
    if (value)
        *data |= (1ULL << (64 - des_pos));
    else
        *data &= ~(1ULL << (64 - des_pos));
}

uint64_t get_left_half(uint64_t value, int total_bits) {
    return value >> (total_bits / 2);
}

uint64_t get_right_half(uint64_t value, int total_bits) {
    uint64_t mask = (1ULL << (total_bits / 2)) - 1;
    return value & mask;
}

uint64_t merge_halves(uint64_t left, uint64_t right, int half_bits) {
    return ((left << half_bits) | right);
}

uint32_t rotate_left(uint32_t value, int shift, int bits) {
    shift %= bits;
    return ((value << shift) | (value >> (bits - shift))) & ((1U << bits) - 1);
}

uint32_t rotate_right(uint32_t value, int shift, int bits) {
    shift %= bits;
    return ((value >> shift) | (value << (bits - shift))) & ((1U << bits) - 1);
}

void swap_halves(uint32_t *left, uint32_t *right) {
    uint32_t tmp = *left;
    *left = *right;
    *right = tmp;
}

uint64_t read_block(FILE *file)
{
    uint8_t buf[8];
    fread(buf, 1, 8, file);

    uint64_t block = 0;
    for (int i = 0; i < 8; i++)
        block = (block << 8) | buf[i];
    return block;
}

void write_block(FILE *file, uint64_t block)
{
    uint8_t buf[8];
    for (int i = 7; i >= 0; i--)
    {
        buf[i] = block & 0xFF;
        block >>= 8;
    }
    fwrite(buf, 1, 8, file);
}

void write_block_hex(FILE *file, uint64_t block)
{
    // Convert the 64-bit block into a 16-character hexadecimal string
    fprintf(file, "%016lX", block);
}