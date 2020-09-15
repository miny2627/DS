#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Hash.h"
using namespace std;

inline int strhashfunc(const char *key)
{
	char *str = (char*)key;
	unsigned int hashval = 0;
	for (hashval = 0; *str; str++)
	{
		hashval = *str + (hashval << 5) - hashval;
	}
	return hashval;
}

inline Hash::Hash()
{
	this->table = table;
	this->size = size;
}

inline void Hash::Create(int tablesize)
{
	this->size = tablesize;
	this->table = new Nptr[tablesize];
	for (int i = 0; i < tablesize; i++)
	{
		table[i] = NULL;
	}
}

inline void Hash::Insert(const char *key)
{
	int index = strhashfunc(key) % size;
	Nptr p = new node;
	p->Data.Key = key;
	p->Data.count = 1;
	p->next = NULL;

	if (!table[index])
	{
		p->next = table[index];
		table[index] = p;
	}
	else
	{
		table[index] = p;
		table[index]->next = NULL;
	}


}

inline Nptr Hash::Search(const char *key)
{
	int index = strhashfunc(key) % size;
	Nptr tmp = table[index];

	if (tmp == NULL)
	{
		cout << "Not found" << endl;
		return NULL;
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->next->Data.Key == key)
			{
				return tmp->next;
			}
			tmp = tmp->next;
		}
	}
	return NULL;
}

inline void Hash::Update(const char *key)
{
	int index = strhashfunc(key) % size;
	if (table[index] == NULL)
	{
		table[index]->Data.Key = key;
		Update(key);
	}
	else if (table[index]->Data.Key == key)
	{
		table[index]->Data.count++;
	}
	else
	{
		table[index] = table[index]->next;
		Update(key);
	}
}

inline void Hash::Delete(const char *key)
{
	int index = strhashfunc(key) % size;
	if (table[index] == NULL)
	{
		cout << "No Element found at key " << key << endl;
		return;
	}
	Nptr tmp = NULL;

	if (table[index]->Data.Key == key)
	{
		tmp = table[index];
		table[index] = table[index]->next;
	}
	else
	{
		Nptr temp = table[index];
		Nptr n = temp->next;
		while (n)
		{
			if (n->Data.Key == key)
			{
				temp->next = n->next;
				tmp = n;
				break;
			}
			temp = n;
			n = temp->next;
		}
	}
}

inline void Hash::Save(const char *filename)
{
	ofstream out(filename, ios::app);
	string a;
	Nptr tmp = new node;
	for (int i = 0; i < size; i++)
	{
		cin >> a;
		tmp = Search(a.c_str());
		out << a << " " << tmp->Data.count << endl;
	}
}

inline void Hash::Open(const char *filename)
{
	ifstream in(filename);
	string s;
	vector<string> v;
	Create(20000);
	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> s;
			v.push_back(s);
		}
	}
	else
	{
		cout << "No file" << endl;
		return;
	}

	string *str = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		str[i] = v[i];
		Insert(str[i].c_str());
	}
}

inline void Hash::Rehash(int newtablesize)
{
	Nptr *temp = new Nptr[newtablesize];
	for (int i = 0; i < newtablesize; i++)
	{
		temp[i] = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		Nptr tmp = table[i];

		while (temp)
		{
			Insert(tmp->Data.Key.c_str());
			tmp = tmp->next;
		}
	}
	this->size = newtablesize;
	this->table = temp;
}