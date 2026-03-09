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

// Choose number of buckets in hash table
const unsigned int N = 65535;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
	unsigned int i = hash(word);
	for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
		if (strcasecmp(word, cursor->word) == 0)
			return true;
	return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
	// https://stackoverflow.com/a/73512149
	unsigned int hash = 0;
	for (int i = 0; word[i]; i++)
		hash = (hash << 2) ^ toupper(word[i]);
	return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
unsigned int count = 0;
bool load(const char *dictionary)
{
	FILE *src = fopen(dictionary, "r");
	if (src == NULL)
		return false;

	char buf[LENGTH + 1];
	while (fscanf(src, "%s", buf) == 1)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			fclose(src);
			return false;
		}
		strcpy(n->word, buf);
		int idx = hash(n->word);
		n->next = table[idx];
		table[idx] = n;
		count++;
	}

	fclose(src);
	return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
	return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
	for (int i = 0; i < N; i++)
	{
		node *cursor = table[i];
		while (cursor != NULL)
		{
			node *tmp = cursor->next;
			free(cursor);
			cursor = tmp;
		}
	}
	return true;
}
