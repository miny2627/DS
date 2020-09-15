#pragma once
template <typename T>
struct node
{
	T Data;
	node* Prev;
	node* Next;
};
template <typename T>
class listClass
{
public:
	listClass();
	listClass(const listClass<T> &L);
	~listClass();
	void Insert(int Position, T item);
	void Delete(int Position);
	void Retrieve(int Position, T & item);
	void print();
	bool isEmpty();
	int Length();
private:
	int Count;
	node<T>* Head;
	node<T>* Tail;
};

template <typename T>
class Queue
{
private:
	node<T>* Head, Tail;
	listClass<T> L;
public:
	Queue();
	Queue(const Queue<T>& Q);
	~Queue();
	void insert(T Item);
	void remove();
	void GetFront(T& Item);
	void Get(int pos, T& Item);
	void display();
	bool isEmpty();
};