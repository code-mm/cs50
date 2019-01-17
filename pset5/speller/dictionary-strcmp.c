/* Implements a dictionary's functionality without hashing of the string.
Therefore it has not optimal runtime. Interesting for performance purposes */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

char** memDictionary = NULL;
int memDictionarySize = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    for (int i = 0; i < memDictionarySize; i++)
    {
        // make the word lower case
        char lowerCaseWord[strlen(word)+1];
        for(int j = 0; j < strlen(word); j++)
        {
            lowerCaseWord[j] = tolower(word[j]);
        }
        lowerCaseWord[strlen(word)] = 0;

        // compare the word against the dictionary
        if (strcmp(lowerCaseWord, memDictionary[i]) == 0)
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
    char* word = malloc(LENGTH * sizeof(char));
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
            memDictionary = realloc(memDictionary, memDictionarySize * sizeof(char**));

            // allocate space and copy word
            memDictionary[memDictionarySize-1] = malloc((wordCharacterCounter+1) * sizeof(char));
            strcpy(memDictionary[memDictionarySize-1], word);

            // reset word counter
            wordCharacterCounter = 0;
        } else {
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
