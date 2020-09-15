#include <iostream>
#include "DoublyListP.h"
using namespace std;

listClass::listClass()
{
	Count = 0;
	Head = NULL;
	Tail = NULL;
}

listClass::listClass(const listClass& L)
{
	Count = L.Count;
	if (L.Head == NULL)
	{
		Head = NULL;
	}
	else
	{
		Head = new node;
		Head->Data = L.Head->Data;
		Nptr temp1 = Head;
		Nptr temp2 = Tail;
		for (Tail = L.Head->Next; temp2 != NULL; temp2 = temp2->Next)
		{
			temp1->Next = new node;
			temp1 = temp1->Next;
			temp1->Data = temp2->Data;
		}
		temp1->Next = NULL;
	}
}
listClass::~listClass()
{
	while (!isEmpty())
	{
		Delete(1);
	}
}
void listClass::Insert(int Position, int Item)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		Nptr p = new node;
		p->Data = Item;

		if (Position == 1)
		{
			p->Next = Head;
			Head = p;
		}
		else
		{
			Nptr temp = Head;
			for (int i = 1; i < (Position - 1); i++)
			{
				temp = temp->Next;
			}
			p->Next = temp->Next;
			temp->Next = p;
		}
		Count++;
	}
}


void listClass::Delete(int Position)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		Nptr temp = Head;
		Nptr temp2 = Head;

		if (Position == 1)
		{
			temp = Head;
			Head = Head->Next;
		}

		for (int i = 1; i < (Position - 1); ++i)
		{
			temp = temp->Next;
		}
		for (int i = 1; i < (Position); ++i)
		{
			temp2 = temp2->Next;
		}
		temp->Next = temp2->Next;
		temp = temp2;

		Count--;
	}
}
bool listClass::isEmpty()
{
	return(Count == 0);
}
int listClass::Length()
{
	return Count;
}
void listClass::print()
{
	Nptr temp;
	temp = Head;
	cout << "[ ";
	while (temp != NULL)
	{
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "]" << endl;
	delete(temp);
}
void listClass::Retrieve(int Position, int & item)
{
	int n = 1;
	Nptr p = Head;
	if (isEmpty()) return;
	else if (0 < Position && Position < Count + 1)
	{
		p = Head;
		while (n < Count + 1)
		{
			if (n == Position)
			{
				item = p->Data;
				break;
			}
			p = p->Next;
			n++;
		}
		cout << Position<<"¹øÂ° : "<<item << endl;
	}
	else
		cout << "Position out of Range" << endl;
}