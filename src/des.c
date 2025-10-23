#include "des.h"
uint64_t DES_encrypt(uint64_t plaintext, uint64_t key)
{
    uint64_t ciphertext;
    ciphertext = permute(plaintext, PERM_IP);
    key_genration(key);
    uint32_t left;
    uint32_t right;

    for (int i = 0; i < 16; i++)
    {
        left = get_left_half(ciphertext, 64);
        right = get_right_half(ciphertext, 64);
        uint32_t tmp = feistel(right, subKeys[i]);
        tmp ^= left;

        left = right;
        right = tmp;
        ciphertext = merge_halves(left, right, 32);
    }

    left = get_left_half(ciphertext, 64);
    right = get_right_half(ciphertext, 64);

    // swap_halves(&left, &right);
    ciphertext = merge_halves(right, left, 32);
    ciphertext = permute(ciphertext, PERM_IP_INV);

    return ciphertext;
}
uint64_t DES_decrypt(uint64_t ciphertext, uint64_t key)
{
    uint64_t plaintext;
    plaintext = permute(ciphertext, PERM_IP);
    key_genration(key);
    uint32_t left;
    uint32_t right;

    for (int i = 0; i < 16; i++)
    {
        left = get_left_half(plaintext, 64);
        right = get_right_half(plaintext, 64);
        uint32_t tmp = feistel(right, subKeys[15-i]);
        tmp ^= left;

        left = right;
        right = tmp;
        plaintext = merge_halves(left, right, 32);
    }

    left = get_left_half(plaintext, 64);
    right = get_right_half(plaintext, 64);

    // swap_halves(&left, &right);
    plaintext = merge_halves(right, left, 32);
    plaintext = permute(plaintext, PERM_IP_INV);

    return plaintext;

}