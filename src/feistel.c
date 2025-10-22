#include "../inc/feistel.h"

uint32_t feistel(uint32_t right,uint64_t key){
    uint64_t expantionAndxor = permute((uint64_t)right, PERM_E);
    expantionAndxor ^= key;
    uint32_t output = sbox_substitute(expantionAndxor);
    output = (uint32_t)permute((uint64_t)output,PERM_P);
    return output;
}
