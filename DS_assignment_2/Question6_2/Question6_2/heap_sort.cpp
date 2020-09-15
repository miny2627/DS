#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heap(int *A, int current, int size)
{
	int i = 2 * current;
	int temp = A[current];
	while (i <= size)
	{
		if (i<size && A[i + 1]>A[i]) i++;
		if (temp > A[i]) break;
		else
		{
			A[i / 2] = A[i];
			i = 2 * i;
		}
	}
	A[i / 2] = temp;
	return;
}

void build_heap(int *A, int size)
{
	for (int i = (size / 2); i >= 1; i--)
	{
		heap(A, i, size);
	}
}

int remove_heap(int *A, int size)
{
	int i = 1;
	int index = A[1];
	A[1] = A[size--];
	heap(A, i, size);

	return index;
}

void heap_sort(int *A, int size)
{
	for (int i = size; i >= 1; i--)
	{
		cout << remove_heap(A, i) << " ";

	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Input the number of the Array >> ";
	cin >> n;
	int *A = new int[n];
	srand((unsigned int)time(NULL));

	cout << endl;
	cout << "# Unsorted array " << endl;
	for (int i = 1; i <= n; i++)
	{
		A[i] = rand() % (n * 2);
		cout << A[i] << " ";
	}
	cout << endl << endl;
	build_heap(A, n);

	cout << "# Build_heap" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;

	cout << "# Sorted array" << endl;
	heap_sort(A, n);
	cout << endl;
	return 0;
}