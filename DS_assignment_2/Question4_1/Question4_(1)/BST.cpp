#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

inline Nptr Search(Nptr T, const char *key)
{
	if (T == NULL)
	{
		cout << "No such Node" << endl;
	}
	else if (T->Data.Key == key)
	{
		return T;
	}
	else if (T->Data.Key > key)
	{
		return Search(T->LChild, key);
	}
	else return Search(T->RChild, key);
}

inline Nptr Insert(Nptr T, const char *key)
{
	if (T == NULL)
	{
		T = new node;
		T->Data.Key = key;
		T->LChild = NULL; T->RChild = NULL;
	}
	else if (T->Data.Key > key)
	{
		T->LChild = Insert(T->LChild, key);
	}
	else if (T->Data.Key == key)
	{
		T->Data.count++;
	}
	else
	{
		T->RChild = Insert(T->RChild, key);
	}
	return T;
}

inline void inorder(Nptr T)
{
	if (T)
	{
		inorder(T->LChild);
		cout << T->Data.Key << " ";
		inorder(T->RChild);
	}
	else
		return;
}

inline void Delete(Nptr &T, const char *key)
{
	if (T == NULL)
	{
		cout << "No Record with Such Key" << endl;
	}
	else if (T->Data.Key > key)
	{
		Delete(T->LChild, key);
	}
	else if (T->Data.Key < key)
	{
		Delete(T->RChild, key);
	}
	else if (T->Data.Key == key)
	{
		if ((T->LChild == NULL) && (T->RChild == NULL))
		{
			Nptr temp = T; T = NULL; delete temp;
		}
		else if (T->LChild == NULL)
		{
			Nptr temp = T; T = T->RChild; delete temp;
		}
		else if (T->RChild == NULL)
		{
			Nptr temp = T; T = T->LChild; delete temp;
		}
		else
		{
			Nptr temp = T->RChild;
			while (temp->LChild != NULL)
			{
				temp = temp->LChild;
			}
			string s = temp->Data.Key;
			const char *c = s.c_str();
			Delete(T, c);
			T->Data.Key = c;
		}
	}
}

inline void Update(Nptr &T, const char *key)
{
	if (T == NULL)
	{
		T = new node;
		T->Data.Key = key;
		T->LChild = NULL; T->RChild = NULL;
		Update(T, key);
	}
	else if (T->Data.Key == key)
	{
		T->Data.count++;
		cout << key << " " << T->Data.count << endl;
	}
	else if (T->Data.Key > key)
		Update(T->LChild, key);
	else 
		Update(T->RChild, key);
}