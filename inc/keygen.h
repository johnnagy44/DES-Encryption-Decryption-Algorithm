#ifndef KEYGEN_H
#define KEYGEN_H

extern uint64_t subKeys[16] ;

uint64_t rotateLeft(uint64_t value, int shift, int bitCount);
void key_genration(uint64_t key);

#endif