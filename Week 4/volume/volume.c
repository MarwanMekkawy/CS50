// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// defining 8bytes & 16bytes types
typedef uint8_t BYTE;
typedef int16_t DBYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy whole header from input file to output file
    BYTE b[44];
    fread(&b, sizeof(b), 1, input);
    fwrite(&b, sizeof(b), 1, output);

    // Read samples from input file and write updated data to output file
    DBYTE d;
    DBYTE factored;

    // copying the value as long as it exists
    while (fread(&d, sizeof(DBYTE), 1, input) != 0)
    {
        // multiplying the copied item by the factor
        factored = d * factor;
        // pasting the value
        fwrite(&factored, sizeof(DBYTE), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
