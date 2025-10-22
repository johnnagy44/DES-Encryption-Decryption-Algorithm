#ifndef FEISTEL_H
#define FEISTEL_H

#include "sbox.h"
#include "permutation.h"

/**
 * @brief Feistel function used in each DES round.
 *
 * Performs: F(R, K) = P( S( E(R) ⊕ K ) )
 *
 * @param right  The 32-bit right half of the data block.
 * @param key    The 48-bit round key.
 * @return       32-bit result of the Feistel function.
 */

uint32_t feistel(uint32_t right,uint64_t key);

#endif