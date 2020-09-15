#pragma once
#include <iostream>
#define NUM_ALPHABET 26

typedef struct trieRecord
{
	int val = 0;
	struct trieRecord **nodes;
} node;

typedef node* Nptr;

inline Nptr CreateTrieNode()
{
	Nptr p = new node;
	p->nodes = new node*[NUM_ALPHABET];

	for (int i = 0; i < NUM_ALPHABET; i++) p->nodes[i] = NULL;
	return p;
}

class Trie
{
public:
	int size;
	Nptr *root;

public:
	void Create();
	void Insert(const char *key, int val);
	Nptr Search(const char *key);
	void Delete(const char *key);
	void Save(const char *filename);
	void Open(const char *filename);
};