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
class stackClass {
public:
	stackClass();
	stackClass(const stackClass<T>& S);
	~stackClass();
	void Push(T Item);
	void Pop();
	bool IsEmpty();
	//bool IsFull();
	void Print();
	void GetTop(T& Item);
	void Get(int pos, T& Item);
private:
	listClass<T> L;
};