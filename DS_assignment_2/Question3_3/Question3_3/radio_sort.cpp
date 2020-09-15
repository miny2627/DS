#include<iostream>
#include<fstream>
#include<string>
#define MAX 100000
#define m 100
using namespace std;

void radix_sort(string *A, int size, int k)
{
	int pos = 1;
	string *str = new string[size];
	int count[m] = { 0 };
	ofstream out("tokens.sorted.txt");

	while (--k >= 0)
	{
		for (int i = 0; i < size; i++) count[(A[i].length() / pos) % 100]++;

		for (int i = 1; i < m; i++) count[i] += count[i - 1];

		for (int i = size - 1; i >= 0; i--) str[--count[(A[i].length() / pos) % 100]] = A[i];

		memcpy(A, str, size * sizeof(int));
		pos *= 100;

		for (int i = 0; i < size; i++) out << str[i] << endl;
	}

	delete[] str;
	delete[] count;
}

int main() {
	string *A = new string[MAX];

	ifstream in("tokens.txt");

	if (in.is_open()) {
		for (int i = 0; !in.eof(); i++)
		{
			in >> A[i];
		}
	}
	else {
		cout << "Can't find the file" << endl;
	}

	radix_sort(A, MAX, 26);

	delete[] A;
	return 0;
}