#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <stdint.h>
#include "utils.h"

/**
 * @file permutation.h
 * @brief DES permutation utilities and lookup tables.
 *
 * This module defines all permutation tables used in DES, such as
 * Initial Permutation (IP), Expansion (E), Permuted Choice 1 and 2 (PC-1, PC-2),
 * and the P-box permutation. It also provides an enumeration and metadata
 * structure to handle all permutations through a single unified interface.
 *
 * Each permutation can be applied via the generic `permute()` function
 * implemented in permutation.c.
 */

/* =========================================================
 *                 Permutation Metadata Types
 * ========================================================= */

/**
 * @brief Enumeration of all DES permutation types.
 */
typedef enum {
    PERM_PC1,      /* Permuted Choice 1: 64-bit key → 56-bit key */
    PERM_PC2,      /* Permuted Choice 2: 56-bit key → 48-bit subkey */
    PERM_IP,       /* Initial Permutation: plaintext → permuted block */
    PERM_IP_INV,   /* Inverse Initial Permutation */
    PERM_E,        /* Expansion Permutation: 32-bit R → 48-bit */
    PERM_P         /* P-box Permutation: 32-bit → 32-bit */
} PermutationType;

/**
 * @brief Metadata for a DES permutation table.
 */
typedef struct {
    const int *table;     /* Pointer to the permutation lookup table */
    int size;             /* Number of output bits */
    int input_bits;       /* Number of input bits */
} PermutationInfo;

/* =========================================================
 *                 Permutation Tables (extern)
 * ========================================================= */

extern const int PC1_TABLE[56];
extern const int PC2_TABLE[48];
extern const int IP_TABLE[64];
extern const int IP_INV_TABLE[64];
extern const int E_TABLE[48];
extern const int P_TABLE[32];

/* =========================================================
 *               Permutation Function Declaration
 * ========================================================= */

/**
 * @brief Apply a DES permutation using the specified permutation type.
 *
 * This function takes an input block and permutes its bits according to
 * the selected DES permutation table (e.g., IP, PC1, PC2, E, P, etc.).
 *
 * @param input   The input block to permute.
 * @param type    The type of permutation to apply.
 * @return        The permuted output block (right-padded in 64 bits).
 */
uint64_t permute(uint64_t input, PermutationType type);

/**
 * @brief Get permutation metadata by type.
 * @param type   The permutation type.
 * @return       Pointer to a PermutationInfo structure describing the permutation.
 */
const PermutationInfo *get_permutation_info(PermutationType type);

#endif // PERMUTATION_H
