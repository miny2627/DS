#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "BST.cpp"
using namespace std;

int main()
{
	ifstream in("The-Road-Not-Taken.tokens.txt");
	const char *c1 = "The-Road-Not-Taken.wordcount.txt";
	ifstream in2("Dickens_Oliver_1839.tokens.txt");
	const char *c2 = "Dickens_Oliver_1839.wordcount.txt";

	string s, s2;
	vector<string> v, v2;
	Nptr T = NULL, n = NULL;
	
	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> s;
			v.push_back(s);
		}
	}
	string *str = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		str[i]=v[i];
		T = Insert(T, str[i].c_str());
		Update(T, str[i].c_str());
	}

	inorder(T, c1);
	
	if (in2.is_open())
	{
		while (!in2.eof())
		{
			in2 >> s2;
			v2.push_back(s2);
		}
	}
	else cout << "Not open" << endl;
	string *str2 = new string[v2.size()];

	for (int i = 0; i < v2.size(); i++)
	{
		str2[i] = v2[i];
		n = Insert(n, str2[i].c_str());
		Update(n, str2[i].c_str());
	}

	inorder(n, c2);


	
	return 0;
}