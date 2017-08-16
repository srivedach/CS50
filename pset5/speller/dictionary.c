/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Load, check and uload the dictionary.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct trie_block
{
	struct trie_block* next[27];
    bool end;
} 
trie_block;

trie_block* root;

int total = 0;

/**
* Returns true if word is in dictionary else false.
*/

bool check(const char* word)
{
	// TODO
    trie_block* ptr = root;
    for(int i=0;word[i] != '\0';i++)
    {
        int c = tolower(word[i]);

        if (c == '\'')
            c='z'+1;

        if (ptr->next[c-'a'] != NULL)
            ptr = ptr->next[c-'a'];
        else
           return false;
    }

    if (ptr->end == true)
       return true;
       
    return false;
 }


/**
 * Loads dictionary into memory.  Returns true if successful else false.
*/

bool load(const char* dictionary)
{
    // TODO
    FILE* file = fopen(dictionary, "r");

    if(file == NULL)
       return false;

    root = calloc(1,sizeof(trie_block)); 
    trie_block* ptr = NULL;

    for(int c = 0;(c=fgetc(file)) != EOF;)
   {
       ptr = root; 
       for( ;c != '\n';ptr = ptr->next[c-'a'],c = fgetc(file))
       {
       		if (c == '\'')
            	c='z'+1;
            if(ptr->next[c-'a'] == NULL)
                ptr->next[c-'a'] = calloc(1,sizeof(trie_block));
        }
        ptr->end = true; 
        total++;
    }    
    fclose(file);
    return true;    
}


/**
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/

unsigned int size(void)
{
    // TODO
    return total;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

void release_blocks(trie_block* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if(ptr->next[i] != NULL)
        {
            release_blocks(ptr->next[i]);
        }
    }
    free(ptr);
}    

bool unload(void)
{
    // TODO
    release_blocks(root);  
    return true;
}