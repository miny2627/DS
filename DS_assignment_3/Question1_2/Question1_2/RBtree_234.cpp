#include <iostream>
#include <assert.h>
#include <string>
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

inline void fixViolation(Nptr &root, Nptr &b)
{
	Nptr parent = NULL;
	Nptr gparent = NULL;

	while ((b != root) && (b->color != BLACK) && (b->MChild->color == RED))
	{
		parent = b->MChild;
		gparent = parent->MChild;

		if (parent == gparent->LChild)
		{
			Nptr uncle = gparent->RChild;

			if (uncle != NULL && uncle->color == RED)
			{
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				b = gparent;
			}
			else
			{
				if (b == parent->RChild)
				{
					rotateLeft(root, parent);
					b = parent;
					parent = b->MChild;
				}

				rotateRight(root, gparent);
				swap(parent->color, gparent->color);
				b = parent;
			}
		}
		else
		{
			Nptr uncle = gparent->LChild;
			if ((uncle != NULL) && (uncle->color == RED))
			{
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				b = gparent;
			}
			else
			{
				if (b == parent->LChild)
				{
					rotateRight(root, parent);
					b = parent;
					parent = b->MChild;
				}

				rotateLeft(root, gparent);
				swap(parent->color, gparent->color);
				b = parent;
			}
		}
	}
	root->color = BLACK;
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
	fixViolation(root, T);
}

inline void RBPrettyPrint(const std::string& prefix, Nptr node, bool isLeft)
{
	if (node != NULL)
	{
		cout << prefix;
		if (node->color == RED) cout << (isLeft ? "   " : "      ");
		else cout << (isLeft ? "曳收收 " : "曲收收 ");

		cout << node->key;

		if (node->color == RED) cout << "*";
		cout << endl;

		RBPrettyPrint(prefix + (isLeft ? "早  " : "  "), node->LChild, true);
		RBPrettyPrint(prefix + (isLeft ? "早  " : "  "), node->RChild, false);
	}
}

inline Nptr minValue(Nptr &n)
{
	Nptr p = n;

	while (p->LChild != NULL)
		p = p->LChild;

	return p;
}

inline void fixDelete(Nptr &p)
{
	if (p == NULL) return;
	if (p == root)
	{
		root = NULL;
		return;
	}

	if (p->color == RED || p->LChild->color == RED || p->RChild->color == RED)
	{
		Nptr child = p->LChild != NULL ? p->LChild : p->RChild;

		if (p == p->MChild->LChild)
		{
			p->MChild->LChild = child;

			if (child != NULL)
				child->MChild = p->MChild;
			child->color = BLACK;
		}
		else
		{
			p->MChild->RChild = child;
			if (child != NULL)
				child->MChild = p->MChild;
			child->color = BLACK;
		}
	}
	else
	{
		Nptr sibling = NULL;
		Nptr parent = NULL;
		Nptr a = p;
		a->color = DBLACK;

		while (a != root && a->color == DBLACK)
		{
			parent = a->MChild;
			if (a == parent->LChild)
			{
				sibling = parent->RChild;
				if (sibling->color == RED)
				{
					sibling->color = BLACK;
					parent->color = RED;
					rotateLeft(root, parent);
				}
				else
				{
					if (sibling->LChild->color == BLACK && sibling->RChild->color == BLACK)
					{
						sibling->color = RED;
						if (parent->color == RED)
							parent->color = BLACK;
						else
							parent->color = DBLACK;
						a = parent;
					}
					else
					{
						if (sibling->RChild->color == BLACK)
						{
							sibling->LChild->color = BLACK;
							sibling->color = RED;
							rotateRight(root, sibling);
							sibling = parent->RChild;
						}
						sibling->color = parent->color;
						parent->color = BLACK;
						sibling->RChild->color = BLACK;
						rotateLeft(root, parent);
						break;
					}
				}
			}
			else
			{
				sibling = parent->LChild;
				if (sibling->color == RED)
				{
					sibling->color = BLACK;
					parent->color = RED;
					rotateRight(root, parent);
				}
				else
				{
					if (sibling->LChild->color == BLACK && sibling->RChild->color == BLACK)
					{
						sibling->color = RED;
						if (parent->color == RED)
							parent->color = BLACK;
						else
							parent->color = DBLACK;
						a = parent;
					}
					else
					{
						if (sibling->LChild->color == BLACK)
						{
							sibling->RChild->color = BLACK;
							sibling->color = RED;
							rotateLeft(root, sibling);
							sibling = parent->LChild;
						}
						sibling->color = parent->color;
						parent->color = BLACK;
						sibling->LChild->color = BLACK;
						rotateRight(root, parent);
						break;
					}
				}
			}
		}
		if (p == p->MChild->LChild)
			p->MChild->LChild = NULL;
		else
			p->MChild->RChild = NULL;
		
		root->color = BLACK;
	}
}

inline Nptr remove(Nptr &root, int Key)
{
	if (root == NULL)
		return root;

	if (Key < root->key)
		return remove(root->LChild, Key);

	if (Key > root->key)
		return remove(root->RChild, Key);

	if (root->LChild == NULL || root->RChild == NULL)
		return root;

	Nptr temp = minValue(root->RChild);
	root->key = temp->key;
	return remove(root->RChild, temp->key);
}

inline void Delete(int Key)
{
	Nptr T = remove(root, Key);
	fixDelete(T);
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

