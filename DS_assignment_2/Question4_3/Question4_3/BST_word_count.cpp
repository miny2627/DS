#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "BST.cpp"
using namespace std;

int main()
{
	Nptr T = NULL;
	vector<string> vs, vs2;
	vector<int> v, v2;
	string s, s2;
	int num, num2;
	char A[100];

	ifstream in("The-Road-Not-Taken.wordcount.txt");
	ifstream in2("Dickens_Oliver_1839.wordcount.txt");

	cout << "> BST¡¬_word¡¬_count¡¬_test The-Road-Not-Taken.wordcount" << endl;
	if (in.is_open())
	{
		cout << "Loading is complete" << endl;
		while (!in.eof())
		{
			in >> s;
			in >> num;
			vs.push_back(s);
			v.push_back(num);
		}
	}

	else
	{
		cout << "No File" << endl;
		return 0;
	}

	string *temp = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		temp[i] = vs[i];
		T = Insert(T, temp[i].c_str());
		Search(T, temp[i].c_str())->Data.count = v[i];
	}

	for(int i=0; i<10; i++)
	{
		cout << "Input> ";
		cin >> A;

		Nptr n = Search(T, A);
		if (n->Data.Key != "\0") cout << n->Data.count << endl;
	}

	cout << endl;
	cout << "> BST¡¬_word¡¬_count¡¬_test Dickens_Oliver_1839.wordcount" << endl;
	if (in2.is_open())
	{
		cout << "Loading is complete" << endl;
		while (!in2.eof())
		{
			in2 >> s2;
			in2 >> num2;
			vs2.push_back(s2);
			v2.push_back(num2);
		}
	}

	else
	{
		cout << "No File" << endl;
		return 0;
	}

	string *temp2 = new string[v2.size()];

	for (int i = 0; i < v2.size(); i++)
	{
		temp2[i] = vs2[i];
		T = Insert(T, temp2[i].c_str());
		Search(T, temp2[i].c_str())->Data.count = v2[i];
	}

	while(1)
	{
		cout << "Input> ";
		cin >> A;

		Nptr n = Search(T, A);
		if (n->Data.Key != "\0") cout << n->Data.count << endl;
	}
	
	return 0;
}