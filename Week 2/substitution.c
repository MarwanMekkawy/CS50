#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string encoder(string text, string args[]);

int main(int size, string args[])
{
    // key validations
    int KeyLength;
    if (size > 1)
    {
        KeyLength = strlen(args[1]);
    }
    if (size != 2)
    {
        printf("usage: %s + 26 chars string \n", args[0]);
        return 1;
    }
    else if (KeyLength != 26)
    {
        printf("Key must contain 26 characters \n");
        return 1;
    }
    for (int i = 0; i < KeyLength; i++)
    {
        if (!isalpha(args[1][i]))
        {
            printf("Key must only contain alphabetic characters \n");
            return 1;
        }
    }
    for (int i = 0; i < KeyLength; i++)
    {
        for (int j = 0; j < KeyLength; j++)
        {
            if (j == i)
            {
                continue;
            }
            else if ((args[1][i]) == (args[1][j]) || (args[1][i]) == ((args[1][j]) + 32) ||
                     ((args[1][i]) + 32) == (args[1][j]))
            {
                printf("Key must not contain repeated characters \n");
                return 1;
            }
        }
    }

    // prompt for plain text
    string PlainText = get_string("enter text to encode:");
    int n = strlen(PlainText);
    char originaltext[n + 1];
    strcpy(originaltext, PlainText);

    // encoding
    string ciphertext = encoder(PlainText, args);

    // print the result
    printf("ciphertext: %s\n", ciphertext);
    printf("plaintext: %s\n", originaltext);
}

// encoder func.
string encoder(string text, string args[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            switch (text[i])
            {
                // Uppercase letters
                case 'A':
                    text[i] = toupper(args[1][0]);
                    break;
                case 'B':
                    text[i] = toupper(args[1][1]);
                    break;
                case 'C':
                    text[i] = toupper(args[1][2]);
                    break;
                case 'D':
                    text[i] = toupper(args[1][3]);
                    break;
                case 'E':
                    text[i] = toupper(args[1][4]);
                    break;
                case 'F':
                    text[i] = toupper(args[1][5]);
                    break;
                case 'G':
                    text[i] = toupper(args[1][6]);
                    break;
                case 'H':
                    text[i] = toupper(args[1][7]);
                    break;
                case 'I':
                    text[i] = toupper(args[1][8]);
                    break;
                case 'J':
                    text[i] = toupper(args[1][9]);
                    break;
                case 'K':
                    text[i] = toupper(args[1][10]);
                    break;
                case 'L':
                    text[i] = toupper(args[1][11]);
                    break;
                case 'M':
                    text[i] = toupper(args[1][12]);
                    break;
                case 'N':
                    text[i] = toupper(args[1][13]);
                    break;
                case 'O':
                    text[i] = toupper(args[1][14]);
                    break;
                case 'P':
                    text[i] = toupper(args[1][15]);
                    break;
                case 'Q':
                    text[i] = toupper(args[1][16]);
                    break;
                case 'R':
                    text[i] = toupper(args[1][17]);
                    break;
                case 'S':
                    text[i] = toupper(args[1][18]);
                    break;
                case 'T':
                    text[i] = toupper(args[1][19]);
                    break;
                case 'U':
                    text[i] = toupper(args[1][20]);
                    break;
                case 'V':
                    text[i] = toupper(args[1][21]);
                    break;
                case 'W':
                    text[i] = toupper(args[1][22]);
                    break;
                case 'X':
                    text[i] = toupper(args[1][23]);
                    break;
                case 'Y':
                    text[i] = toupper(args[1][24]);
                    break;
                case 'Z':
                    text[i] = toupper(args[1][25]);
                    break;

                // Lowercase letters
                case 'a':
                    text[i] = tolower(args[1][0]);
                    break;
                case 'b':
                    text[i] = tolower(args[1][1]);
                    break;
                case 'c':
                    text[i] = tolower(args[1][2]);
                    break;
                case 'd':
                    text[i] = tolower(args[1][3]);
                    break;
                case 'e':
                    text[i] = tolower(args[1][4]);
                    break;
                case 'f':
                    text[i] = tolower(args[1][5]);
                    break;
                case 'g':
                    text[i] = tolower(args[1][6]);
                    break;
                case 'h':
                    text[i] = tolower(args[1][7]);
                    break;
                case 'i':
                    text[i] = tolower(args[1][8]);
                    break;
                case 'j':
                    text[i] = tolower(args[1][9]);
                    break;
                case 'k':
                    text[i] = tolower(args[1][10]);
                    break;
                case 'l':
                    text[i] = tolower(args[1][11]);
                    break;
                case 'm':
                    text[i] = tolower(args[1][12]);
                    break;
                case 'n':
                    text[i] = tolower(args[1][13]);
                    break;
                case 'o':
                    text[i] = tolower(args[1][14]);
                    break;
                case 'p':
                    text[i] = tolower(args[1][15]);
                    break;
                case 'q':
                    text[i] = tolower(args[1][16]);
                    break;
                case 'r':
                    text[i] = tolower(args[1][17]);
                    break;
                case 's':
                    text[i] = tolower(args[1][18]);
                    break;
                case 't':
                    text[i] = tolower(args[1][19]);
                    break;
                case 'u':
                    text[i] = tolower(args[1][20]);
                    break;
                case 'v':
                    text[i] = tolower(args[1][21]);
                    break;
                case 'w':
                    text[i] = tolower(args[1][22]);
                    break;
                case 'x':
                    text[i] = tolower(args[1][23]);
                    break;
                case 'y':
                    text[i] = tolower(args[1][24]);
                    break;
                case 'z':
                    text[i] = tolower(args[1][25]);
                    break;
            }
        }
    }
    return text;
}
