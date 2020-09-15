#pragma once
#define RED true
#define BLACK false
#define DBLACK false

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
		this->color = RED;
		LChild = RChild = MChild = NULL;
	}
}node;

typedef node* Nptr;
static Nptr root = NULL;