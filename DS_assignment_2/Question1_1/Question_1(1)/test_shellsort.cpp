#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "shellsort.h"
using namespace std;

int main()
{
	//Random
	int n;
	cout << "Input the size of the Array >> ";
	cin >> n;
	int *A = new int[n];
	srand(time(0));
	cout << "Unsorted array : " << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % (2 * n);
		cout << A[i] << " ";
	}
	cout << endl;
	shellsort(A, n, 3);
	cout << "Sorted array : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl<< endl;

	//File
	ifstream in("input.txt");
	int num[10];
	for (int i = 0; !in.eof(); i++)
	{
		in >> num[i];
	}

	cout << "File unsorted :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;

	cout << "File sorted : " << endl;
	shellsort(num, 10, 3);
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}

	return 0;
}