#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    int length = strlen(text);

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text, length);
    int words = count_words(text, length);
    int sentences = count_sentences(text, length);

    // Compute the Coleman-Liau index
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text, int length)
{
    // Return the number of letters in text
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text, int length)
{
    // Return the number of words in text
    int Spaces = 0;
    bool WasASpace = false;
    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]) && WasASpace == false)
        {
            WasASpace = true;
            Spaces++;
        }
        else
        {
            WasASpace = false;
        }
    }
    return Spaces + 1;
}

int count_sentences(string text, int length)
{
    // Return the number of sentences in text
    int Puncts = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            Puncts++;
        }
    }
    return Puncts;
}
