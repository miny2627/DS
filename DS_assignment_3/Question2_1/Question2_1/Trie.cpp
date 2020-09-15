#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Trie.h"
using namespace std;

inline void Trie::Create()
{
	Nptr T = CreateTrieNode();
	this->root = T->nodes;
}

inline void Trie::Insert(const char *key, int val)
{
	string s = key;
	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		if (!root[index])
		{
			root[index]->val = val + 1;
		}
		else
			root[index]->val = val;
	}
}

inline Nptr Trie::Search(const char *key)
{
	string s = key;
	Nptr tmp = new node;
	if (root == NULL) return NULL;

	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		if (!root[index]) cout << "false" << endl;
		tmp = root[index];
	}
	return tmp;
}

inline void Trie::Delete(const char *key)
{
	
}

inline void Trie::Save(const char *filename)
{
	ofstream out(filename, ios::app);
	string a;
	Trie tmp;
	Nptr T;
	for (int i = 0; i < size; i++)
	{
		T = tmp.Search(a.c_str());
		out << a << " " << T->val << endl;
	}
}

inline void Trie::Open(const char *filename)
{
	ifstream in(filename);
	string s;
	vector<string> v;

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
		Insert(str[i].c_str(), 0);
	}
}