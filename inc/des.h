#ifndef DES_H
#define DES_H

#include "utils.h"
#include "feistel.h"
#include "permutation.h"
#include "sbox.h"
#include "keygen.h"

uint64_t DES_encrypt(uint64_t plaintext,uint64_t key);
uint64_t DES_decrypt(uint64_t ciphertext,uint64_t key);

#endif