#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdio.h>

/**
 * @file utils.h
 * @brief Utility functions for bit manipulation and file I/O used in DES implementation.
 *
 * This module provides low-level helper functions for manipulating bits,
 * rotating data segments, merging/splitting halves, and reading/writing
 * 64-bit blocks from files. These utilities are shared across multiple
 * DES components such as key scheduling, permutation, and encryption.
 */

/* =========================================================
 *                 Bit Manipulation Helpers
 * ========================================================= */

/**
 * @brief Get a specific bit from a 64-bit value.
 * @param data      The input 64-bit value.
 * @param des_pos   The bit position to extract (0 = least significant bit).
 * @return          The bit value (0 or 1).
 */
uint8_t get_bit(uint64_t data, int des_pos);

/**
 * @brief Set or clear a specific bit in a 64-bit value.
 * @param data      Pointer to the 64-bit value to modify.
 * @param des_pos   Bit position to modify (0 = least significant bit).
 * @param value     The bit value to set (0 or 1).
 */
void set_bit(uint64_t *data, int des_pos, uint8_t value);

/**
 * @brief Perform a circular left rotation on a given value.
 * @param value     The input value to rotate.
 * @param shift     Number of bits to rotate by.
 * @param bits      Bit width of the segment to rotate (e.g., 28 for DES halves).
 * @return          The rotated value.
 */
uint32_t rotate_left(uint32_t value, int shift, int bits);

/**
 * @brief Perform a circular right rotation on a given value.
 * @param value     The input value to rotate.
 * @param shift     Number of bits to rotate by.
 * @param bits      Bit width of the segment to rotate.
 * @return          The rotated value.
 */
uint32_t rotate_right(uint32_t value, int shift, int bits);

/* =========================================================
 *                 Block and Half Manipulation
 * ========================================================= */

/**
 * @brief Merge two halves into a single value.
 * @param left       Left half value.
 * @param right      Right half value.
 * @param half_bits  Bit width of each half (e.g., 32 or 28).
 * @return           Combined 64-bit value (left concatenated with right).
 */
uint64_t merge_halves(uint64_t left, uint64_t right, int half_bits);

/**
 * @brief Swap two 32-bit halves.
 * @param left   Pointer to the left half.
 * @param right  Pointer to the right half.
 */
void swap_halves(uint32_t *left, uint32_t *right);

/**
 * @brief Extract the left half from a 64-bit value.
 * @param value       The 64-bit input.
 * @param total_bits  Total bit width (e.g., 64 or 56).
 * @return            The left half as a 64-bit value (right-padded with zeros).
 */
uint64_t get_left_half(uint64_t value, int total_bits);

/**
 * @brief Extract the right half from a 64-bit value.
 * @param value       The 64-bit input.
 * @param total_bits  Total bit width (e.g., 64 or 56).
 * @return            The right half as a 64-bit value (right-padded with zeros).
 */
uint64_t get_right_half(uint64_t value, int total_bits);

/* =========================================================
 *                        File I/O
 * ========================================================= */

/**
 * @brief Read an 8-byte (64-bit) block from a binary file.
 * @param file   Pointer to the open file.
 * @return       The 64-bit block read from the file. Returns 0 on EOF.
 */
uint64_t read_block(FILE *file);

/**
 * @brief Write an 8-byte (64-bit) block to a binary file.
 * @param file   Pointer to the open file.
 * @param block  The 64-bit block to write.
 */
void write_block(FILE *file, uint64_t block);
void write_block_hex(FILE *file, uint64_t block);

#endif // UTILS_H
