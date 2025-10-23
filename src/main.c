#include <stdio.h>
#include "des.h"

int main(int argc, char **argv)
{
    // to be edited
    char mod = argv[1][0];
    printf("%c\n", mod);
    char *key_file = argv[2];
    char *input_file = argv[3];
    char *output_file = argv[4];

    FILE *key = fopen(key_file, "rb");
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    uint64_t key_value = read_block(key);
    while (1)
    {
        uint64_t block = read_block(in);
        if (feof(in))
            break;

        uint64_t result;
        if (mod == 'e')
            result = DES_encrypt(block, key_value);
        else if (mod == 'd')
            result = DES_decrypt(block, key_value);
        write_block(out, result);
        //write_block_hex(out, result);
    }

    fclose(in);
    fclose(out);
}
