#include <stdio.h>
#include <stdint.h>
#include "permutation.h"
#include "keygen.h"

uint64_t subKeys[16]={0};

const int keyIntialPermutationTable_c[28] = {
    57,
    49,
    41,
    33,
    25,
    17,
    9,
    1,
    58,
    50,
    42,
    34,
    26,
    18,
    10,
    2,
    59,
    51,
    43,
    35,
    27,
    19,
    11,
    3,
    60,
    52,
    44,
    36,

};
const int keyIntialPermutationTable_d[28] = {
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4};

const int leftShiftsTable[16] = {
    1, 1, 2, 2,
    2, 2, 2, 2,
    1, 2, 2, 2,
    2, 2, 2, 1};

const int subKeysPermutationTable[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32};

// const int subKeysPermutationTable_d[24] = {};



/*
uint64_t permute(uint64_t input, const int *table, int table_size) {
    uint64_t output = 0;
    for (int i = 0; i < table_size; i++) {
        int bit_position = table[i];
        uint64_t bit = (input >> (64 - bit_position)) & 0x01; // Extract the bit
        output |= (bit << (table_size -1 - i )); // Set the bit in the output
    }
    return output;
}
*/
uint64_t rotateLeft(uint64_t value, int shift, int bitCount)
{
    shift %= bitCount; // in case shift > bitCount
    return ((value << shift) | (value >> (bitCount - shift))) & ((1ULL << bitCount) - 1);
}

void key_genration(uint64_t key)
{
    uint64_t newKey = permute(key, PERM_PC1);
    uint64_t c = (newKey >> 28) & 0x0FFFFFFF;
    uint64_t d = newKey & 0x0FFFFFFF;
    for (int i = 0; i < 16; i++)
    {
        c = rotateLeft(c, leftShiftsTable[i], 28);
        d = rotateLeft(d, leftShiftsTable[i], 28);
        uint64_t combined = (c << 28) | d;
        subKeys[i] = permute(combined, PERM_PC2);
    }
};
/*
int main() {
    printf("Hello, micho!\n");
    uint64_t n = 0x6b65703100000000;
   
    uint64_t newKey= permute(n, PERM_PC1);
    printf("%llx\n", newKey);

    uint64_t c = (newKey >> 28) & 0x0FFFFFFF;
    uint64_t d = newKey & 0x0FFFFFFF;
    printf("%llx\n", c);
    printf("%llx\n", d);

key_genration(n);

printf("%llx\n", subKeys[0]);
printf("%llx\n", subKeys[1]);
printf("%llx\n", subKeys[2]);
printf("%llx\n", subKeys[3]);
printf("%llx\n", subKeys[4]);
printf("%llx\n", subKeys[5]);

return 0;
}
*/