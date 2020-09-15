#pragma once
#include <string>
typedef struct dataRecord
{
	std::string Key;
	int count = 0;
} dataType;

typedef struct nodeRecord
{
	dataType Data;
	struct nodeRecord* next;
} node;

typedef node* Nptr;

class Hash
{
public:
	int size;
	Nptr *table;
	Hash();
	void Create(int tablesize);
	void Insert(const char *key);
	Nptr Search(const char *key);
	void Update(const char *key);
	void Delete(const char *key);
	void Save(const char *filename);
	void Open(const char *filename);
	void Rehash(int newtablesize);
};