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
	for (int i = (size/2); i >= 1; i--)
	{
		heap(A, i, size);
	}
}

int main()
{
	int n;
	cout << "Input the number of the Array >> ";
	cin >> n;
	int *A = new int[n];
	srand((unsigned int)time(NULL));
	
	cout << endl;
	cout << "Unsorted array" << endl;

	for (int i = 1; i <= n; i++)
	{
		A[i] = rand() % (n * 2);
		cout << A[i] << " ";
	}
	cout << endl << endl;

	build_heap(A, n);
	cout << "Build_Heap" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}