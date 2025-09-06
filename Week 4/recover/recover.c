#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t Byte;
FILE *dst = NULL;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc < 2)
    {
        printf("Usage: %s [memory name]\n", argv[0]);
        return 1;
    }

    // Open the memory card
    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        perror("Error opening source file \n");
        return 2;
    }

    // While there's still data left to read from the memory card
    Byte buffer[512];
    int fcount = 0;
    char filename[16];
    while (fread(&buffer, sizeof(buffer), 1, src) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if there is a file opend close it and make new one
            if (dst != NULL)
            {
                fclose(dst);
            }

            sprintf(filename, "%03i.jpg", fcount);
            dst = fopen(filename, "wb");

            // keeping track of files number
            fcount++;
        }

        if (dst != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, dst);
        }
    }
    // closes the last file
    if (dst != NULL)
    {
        fclose(dst);
    }
    fclose(src);
    return 0;
}
