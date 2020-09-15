#pragma once
#define RED true
#define BLACK false

typedef struct treeRecord
{
	int key;
	struct treeRecord *LChild;
	struct treeRecord *RChild;
	struct treeRecord *MChild;
	bool color;

	treeRecord(int key)
	{
		this->key = key;
		LChild = MChild = RChild = NULL;
		this->color = RED;
	}
}node;

typedef node* Nptr;
static Nptr root = NULL;