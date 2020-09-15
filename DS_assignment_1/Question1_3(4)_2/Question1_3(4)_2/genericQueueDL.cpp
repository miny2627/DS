#include <iostream>
#include "genericQueueDL.h"
using namespace std;

template <typename T>
listClass<T>::listClass()
{
	Count = 0;
	Head = NULL;
	Tail = NULL;
}
template <typename T>
listClass<T>::listClass(const listClass<T>& L)
{
	Count = L.Count;
	if (L.Head == NULL)
	{
		Head = NULL;
	}
	else
	{
		Head = new node<T>;
		Head->Data = L.Head->Data;
		node<T>* temp1 = Head;
		node<T>* temp2 = Tail;
		for (Tail = L.Head->Next; temp2 != NULL; temp2 = temp2->Next)
		{
			temp1->Next = new node<T>;
			temp1 = temp1->Next;
			temp1->Data = temp2->Data;
		}
		temp1->Next = NULL;
	}
}
template <typename T>
listClass<T>::~listClass()
{
	while (!isEmpty())
	{
		Delete(1);
	}
}
template <typename T>
void listClass<T>::Insert(int Position, T Item)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		node<T>* p = new node<T>;
		p->Data = Item;

		if (Position == 1)
		{
			p->Next = Head;
			Head = p;
		}
		else
		{
			node<T>* temp = Head;
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
template <typename T>
void listClass<T>::Delete(int Position)
{
	if ((Position > Count + 1) || (Position < 1))
	{
		cout << "Position out of Range" << endl;
	}
	else
	{
		node<T>* temp = Head;
		node<T>* temp2 = Head;

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
template <typename T>
bool listClass<T>::isEmpty()
{
	return(Count == 0);
}
template <typename T>
int listClass<T>::Length()
{
	return Count;
}
template <typename T>
void listClass<T>::print()
{
	node<T>* temp;
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
template <typename T>
void listClass<T>::Retrieve(int Position, T & item)
{
	int n = 1;
	node<T>* p = Head;
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
		cout << Position << "¹øÂ° : " << item << endl;
	}
	else
		cout << "Position out of Range" << endl;
}

template <typename T>
Queue<T>::Queue()
{
}
template <typename T>
Queue<T>::Queue(const Queue<T>& Q)
{
	L = Q.L;
}
template <typename T>
Queue<T>::~Queue()
{
	while (!isEmpty())
		remove();
}
template <typename T>
void Queue<T>::insert(T Item)
{
	L.Insert(L.Length() + 1, Item);
}
template <typename T>
void Queue<T>::remove()
{
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else
		L.Delete(1);

}
template <typename T>
bool Queue<T>::isEmpty()
{
	return (L.isEmpty());
}
template <typename T>
void Queue<T>::display()
{
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		L.print();
	}
}
template <typename T>
void Queue<T>::GetFront(T& Item)
{
	L.Retrieve(1, Item);
}
template <typename T>
void Queue<T>::Get(int pos, T& Item)
{
	L.Retrieve(pos, Item);
}