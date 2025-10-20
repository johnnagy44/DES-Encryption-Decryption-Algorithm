#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
    //to be edited
    char * input_file=argv[2];
    char * output_file=argv[2];
    char * key=argv[2];

    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    while (1)
    {
        uint64_t block = read_block(in);
        if (feof(in))
            break;

        uint64_t result = des_encrypt_block(block, key); // or des_decrypt_block()
        write_block(out, result);
    }

    fclose(in);
    fclose(out);
}
