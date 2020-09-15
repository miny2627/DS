#include <iostream>
#include <string>
#include <cmath>
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

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == 'log' || ch == 'pow' || ch == 'sqrt')
		return true;
	else
		return false;
}
int pre(char op)
{
	switch (op)
	{
	case '(':case ')':
		return 0; break;
	case '+':case '-':
		return 1; break;
	case '*':case '/':case 'log':case'pow':case 'sqrt':
		return 2; break;
	}
	return -1;
}
double calculate(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case 'pow':
		return pow(a, b);
		break;
	case 'log':
		b = 0;
		return log(a + b);
		break;
	case 'sqrt':
		b = 0;
		return sqrt(a + b);
		break;
	}
}

double result(string tokens)
{
	stackClass<double> d;
	stackClass<string> s;

	for (int i = 0; i < tokens.length(); i++)
	{
		if (tokens[i] == ' ')
			continue;
		else if (tokens[i] == '(')
		{
			char a = '(';
			string str = "";
			str = a + "";
			s.Push(str);
		}
		else if (isdigit(tokens[i]))
		{
			double val = 0;
			while (i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val * 10) + (tokens[i] - '0');
				i++;
			}
			d.Push(val);
		}
		else if (tokens[i] == ')')
		{
			string str;
			s.GetTop(str);
			char a = str.at(0);
			while (!s.IsEmpty() && a != '(')
			{
				double val2;
				d.GetTop(val2);
				d.Pop();

				double val1;
				d.GetTop(val1);
				d.Pop();

				string op;
				s.GetTop(op);
				char c = op.at(0);
				s.Pop();

				d.Push(calculate(val1, val2, c));
			}
			s.Pop();
		}
		else
		{
			string str;
			s.GetTop(str);
			char op = str.at(0);
			while (!s.IsEmpty() && pre(op) >= pre(tokens[i]))
			{
				double val2;
				d.GetTop(val2);
				d.Pop();

				double val1;
				d.GetTop(val1);
				d.Pop();

				string op;
				s.GetTop(op);
				char c = op.at(0);
				s.Pop();

				d.Push(calculate(val1, val2, c));
			}
			char a = tokens[i];
			string st = "";
			st = a + "";
			s.Push(st);;
		}
	}
	while (!s.IsEmpty())
	{
		double val2;
		d.GetTop(val2);
		d.Pop();

		double val1;
		d.GetTop(val1);
		d.Pop();

		string op;
		s.GetTop(op);
		char c = op.at(0);
		s.Pop();

		d.Push(calculate(val1, val2, c));
	}
	double t;
	d.GetTop(t);

	return t;
}

int main()
{
	string input;
	cout << "Enter an expression : " << endl;
	getline(cin, input);
	cout << result(input) << endl;

	return 0;
}