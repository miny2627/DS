#include <iostream>
#include <string>
#include <assert.h>
#include "RBtree.h"
using namespace std;

inline void rotateLeft(Nptr &root, Nptr &b)
{
	Nptr right = b->RChild;
	b->RChild = right->LChild;

	if (b->RChild != NULL)
	{
		b->RChild->MChild = b;
	}
	right->MChild = b->MChild;

	if (b->MChild == NULL)
	{
		root = right;
	}
	else if (b == b->MChild->LChild)
	{
		b->MChild->LChild = right;
	}
	else
	{
		b->MChild->RChild = right;
	}
	right->LChild = b;
	b->MChild = right;
}

inline void rotateRight(Nptr &root, Nptr &b)
{
	Nptr left = b->LChild;
	b->LChild = left->RChild;

	if (b->LChild != NULL)
	{
		b->LChild->MChild = b;
	}
	left->MChild = b->MChild;

	if (b->MChild == NULL)
	{
		root = left;
	}
	else if (b == b->MChild->LChild)
	{
		b->MChild->LChild = left;
	}
	else
	{
		b->MChild->RChild = left;
	}
	left->RChild = b;
	b->MChild = left;
}

inline Nptr add(Nptr root, Nptr b)
{
	if (root == NULL) return b;
	if (root->key > b->key)
	{
		root->LChild = add(root->LChild, b);
		root->LChild->MChild = root;
	}
	else if (b->key > root->key)
	{
		root->RChild = add(root->RChild, b);
		root->RChild->MChild = root;
	}
	return root;
}

inline void insert(int Key)
{
	Nptr T = new treeRecord(Key);
	root = add(root, T);
}

inline void Delete(int Key)
{

}

inline void RBPrettyPrint(const std::string& prefix, Nptr node, bool isLeft)
{
	if (node != NULL)
	{
		cout << prefix;
		if (node->color == RED) cout << (isLeft ? " " : "        ");
		else cout << (isLeft ? "曳收收" : "曲收收");

		cout << node->key;

		if (node->color == RED) cout << "*";
		cout << endl;

		RBPrettyPrint(prefix + (isLeft ? "早 " : " "), node->LChild, true);
		RBPrettyPrint(prefix + (isLeft ? "早 " : " "), node->RChild, false);
	}
}

inline void verify_property_1(Nptr p)
{
	assert(p->color == RED || p->color == BLACK);
	if (p == NULL)
		return;
	verify_property_1(p->LChild);
	verify_property_1(p->RChild);
}

inline void verify_property_2(Nptr root)
{
	assert(root->color == BLACK);
}

inline void verify_property_4(Nptr p)
{
	if (p->color == RED)
	{
		assert(p->LChild == BLACK);
		assert(p->RChild == BLACK);
		assert(p->MChild == BLACK);
	}
	if (p == NULL)
		return;
	verify_property_4(p->LChild);
	verify_property_4(p->RChild);
}

inline void RBVerify()
{
	verify_property_1(root);
	verify_property_2(root);
	verify_property_4(root);
}