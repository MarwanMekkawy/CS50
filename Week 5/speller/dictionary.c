// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// number of buckets in hash table//////////////////////////////////////////////////
// const unsigned int N = 26;
// enhanced hashtable using bigger prime number as buckets
const unsigned int N = 1009;

// Hash table
node *table[N];

// words count loaded
int Count = 0;

// Returns true if word is in dictionary, else false////////////////////////////////
bool check(const char *word)
{
    unsigned int hashed = hash(word);
    node *cursor = table[hashed];
    while (cursor != NULL)
    {

        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number///////////////////////////////////////////////////////////
unsigned int hash(const char *word)
{
    // old hash function
    // return toupper(word[0]) - 'A';

    // new hash function [hashes the whole name, taking in consideration the position of the letter
    // and if there will be a (')]
    unsigned int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += (toupper(word[i]) - 'A') >= 0 ? (toupper(word[i]) - 'A') * (i + 1) : 100 * (i + 1);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false////////////
bool load(const char *dictionary)
{
    // temp to save the word
    char wordTemp[LENGTH + 1];
    int hashed;
    node *cursor = NULL;

    // opening file
    FILE *Dictionary = fopen(dictionary, "r");
    if (Dictionary == NULL)
    {
        return false;
        fclose(Dictionary);
    }
    // making a node in the list for each word
    while (fscanf(Dictionary, "%s", wordTemp) != EOF)
    {
        // update the cursor
        hashed = hash(wordTemp);
        cursor = table[hashed];

        // creat and attach the new node
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            return false;
        }
        strcpy(newnode->word, wordTemp);
        newnode->next = cursor;
        table[hashed] = newnode;
        Count++;
    }
    fclose(Dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded/////////
unsigned int size(void)
{
    return Count;
}

// Unloads dictionary from memory, returning true if successful, else false//////////
bool unload(void)
{
    node *cursor = NULL;
    node *temp = NULL;

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            temp = cursor->next;
            free(cursor);
            cursor = temp;
        }
    }
    return true;
}
