#pragma once
#include <string>
typedef struct dataRecord
{
	std::string Key;
	int count = 0;
} dataType;

typedef struct treeRecord
{
	dataType Data;
	struct treeRecord* LChild;
	struct treeRecord* RChild;
} node;

typedef node* Nptr;