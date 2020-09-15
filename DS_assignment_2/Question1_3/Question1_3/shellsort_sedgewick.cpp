#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "shellsort_sedgewick.h"
using namespace std;

void insertionsort(int *A, int size, int start, int h)
{
	int tmp, j;
	for (int i = start + h; i < size; i += h)
	{
		tmp = A[i];
		for (j = i - h; j >= start && A[j] > tmp; j -= h)
		{
			A[j + h] = A[j];
		}
		A[j + h] = tmp;
	}
}

void shellsort_sedgewick(int *A, int size)
{
	int h, i;
	for (i = 0; pow(4.0, i + 1) + 3 * pow(2.0, i) + 1 < size; i++);
	i--;
	
	for (; i >= 0; i--)
	{
		if (i == 0)
		{
			h = 1;
		}
		else
			h = pow(4.0, i) + 3 * pow(2.0, i - 1) + 1;

		insertionsort(A, size, i, h);
	}
	
}

int main()
{
	int n;
	cout << "Input the number of the Array >> ";
	cin >> n;
	int *A = new int[n];
	srand(time(0));

	cout << "Unsorted Array : " << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 50;
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Sorted Array : " << endl;
	shellsort_sedgewick(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}