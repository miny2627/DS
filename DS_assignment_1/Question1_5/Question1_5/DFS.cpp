#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

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
	}
	else
		cout << "Position out of Range" << endl;
}

template <typename T>
stackClass<T>::stackClass()
{

}
template <typename T>
stackClass<T>::stackClass(const stackClass<T>& S)
{
	L = S.L;
}
template <typename T>
stackClass<T>::~stackClass()
{
	while (!IsEmpty())
		Pop();
}
template <typename T>
bool stackClass<T>::IsEmpty()
{
	return bool(L.isEmpty());
}
template <typename T>
void stackClass<T>::Push(T Item)
{
	L.Insert(1, Item);
}
template <typename T>
void stackClass<T>::Pop()
{
	if (IsEmpty()) cout << "Stack is empty" << endl;
	else L.Delete(1);
}
template <typename T>
void stackClass<T>::GetTop(T &Item)
{
	L.Retrieve(1, Item);
}
template <typename T>
void stackClass<T>::Get(int pos, T& Item)
{
	L.Retrieve(pos, Item);
}
template <typename T>
void stackClass<T>::Print()
{
	L.print();
}

class Graph
{
private:
	int n;
	int **A;
public:
	Graph(int size = 2);
	~Graph()
	{
		for (int i = 0; i < n; ++i)
		{
			delete[] A[i];
		}
		delete[] A;
	}
	bool isConnected(int x, int y)
	{
		return (A[x - 1][y - 1] == 1);
	}
	void addEdge(int x, int y)
	{
		A[x - 1][y - 1] = A[y - 1][x - 1] = 1;
	}
	void DFS(int start, int end)
	{
		stackClass<int> s;
		bool *visited = new bool[n];
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		s.Push(start);
		visited[start-1] = true;

		if (start == end) return;
		cout << "enter starting and ending vertices> ";
		cout << start << " " << end << endl;
		
		while (!s.IsEmpty())
		{
			int k;
			s.GetTop(k);
			s.Pop();

			cout << k << " ";
			if (k == end) break;
			for (int i = k; i<= end; i++)
			{
				if (isConnected(k, i) && !visited[i-1])
				{
					s.Push(i);
					visited[i-1] = true;
				}
			}
		}
		cout << endl;

		if (s.IsEmpty()) cout << "not found" << endl;

		delete[] visited;
		cout << endl;
	}
};
Graph::Graph(int size)
{
	if (size < 2) n = 2;
	else n = size;
	A = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			A[i][j] = 0;
	}
}

int main()
{
	ifstream input("sample_graph.txt");
	
	if (input.is_open())
	{
		int a, b;
	}

	Graph g(9);
	g.addEdge(1, 2); g.addEdge(1, 7); g.addEdge(2, 3);
	g.addEdge(2, 5); g.addEdge(3, 4); g.addEdge(4, 2);
	g.addEdge(5, 6); g.addEdge(5, 7); g.addEdge(7, 8);
	g.addEdge(8, 9); g.addEdge(9, 2);
	g.DFS(1, 9); g.DFS(1, 6); g.DFS(3, 6);
	g.DFS(5, 1); g.DFS(8, 1);

	return 0;
}