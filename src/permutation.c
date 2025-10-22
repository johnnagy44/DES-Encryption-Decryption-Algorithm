#include <stdint.h>
#include "../inc/permutation.h"

uint64_t permute(uint64_t input, const int *table, int table_size) {
    uint64_t output = 0;
    for (int i = 0; i < table_size; i++) {
        int bit_position = table[i]; 
        uint64_t bit = (input >> (64 - bit_position)) & 0x01; // Extract the bit
        output |= (bit << (table_size -1 - i )); // Set the bit in the output
    }
    return output;
}