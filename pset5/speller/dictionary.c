// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

unsigned long *memDictionary = NULL;
int memDictionarySize = 0;

// create hash from string with djb2 algorithm
// code adapted from: http://www.cse.yorku.ca/~oz/hash.html
unsigned long djb2Hash(const char *word)
{
    // make the word lower case
    char lowerCaseWord[strlen(word) + 1];
    for(int i = 0; i < strlen(word); i++)
    {
        lowerCaseWord[i] = tolower(word[i]);
    }
    lowerCaseWord[strlen(word)] = 0;

    // hash the word
    unsigned long hash = 5381;

    for (int i = 0; i < strlen(word); i++)
    {
        hash = ((hash << 5) + hash) + lowerCaseWord[i];
    }

    return hash;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned long hashedWord = djb2Hash(word);
    for (int i = 0; i < memDictionarySize; i++)
    {
        // compare the word hash against the dictionary
        if (hashedWord == memDictionary[i])
        {
            return true;
        }    
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
	// open file for read access
    FILE *infile = fopen(dictionary, "rb");
    if (infile == NULL)
    {
    	return false;
    }

    // temporary space for read word
    char* word = malloc((LENGTH + 1) * sizeof(char));
    int wordCharacterCounter = 0;

    // extract words from file
    while (fread(word+wordCharacterCounter, 1, 1, infile) == 1)
    {
        // check if end of word reached
        if (word[wordCharacterCounter] == 10)
        {
            // set null character for end of word
            word[wordCharacterCounter] = 0;

            // resize dictionary
            memDictionarySize++;
            memDictionary = realloc(memDictionary, memDictionarySize * sizeof(unsigned long));

            // hash word and write to array
            memDictionary[memDictionarySize - 1] = djb2Hash(word);

            // reset word counter
            wordCharacterCounter = 0;
        }
        else
        {
            // increase word counter in case of normal letter
            wordCharacterCounter++;
        }
    }

    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return memDictionarySize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    free(memDictionary);
    memDictionarySize = 0;
    return true;
}
