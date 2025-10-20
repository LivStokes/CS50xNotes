#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE; // Gives me a byte of 8 ints.

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) // starts a loop that iterates over the file called src, byte by byte.
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}