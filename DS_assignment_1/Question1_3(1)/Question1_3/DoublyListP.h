#pragma once
typedef struct nodeRecord
{
	int Data;
	struct nodeRecord *Prev, *Next;
}node;

typedef node* Nptr;
class listClass
{
	public:
		listClass();
		listClass(const listClass &L);
		~listClass();
		void Insert(int Position, int Item);
		void Delete(int Position);
		void Retrieve(int Position, int & item);
		bool isEmpty();
		int Length();
		void print();
	private:
		int Count;
		Nptr Head;
		Nptr Tail;
};