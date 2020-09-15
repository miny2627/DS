#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mergesort.cpp"
#include "quicksort.cpp"
using namespace std;

int main()
{
	int n;
	cout << "Input the size of the Array >> ";
	cin >> n;
	int *A = new int[n];
	srand(time(0));

	cout << "# Mergesort" << endl;
	cout << "Given array is" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % (2 * n);
		cout << A[i] << " ";
	}
	cout << endl << endl;
	mergesort(A, 0, n - 1);
	cout << "Sorted array is" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;

	int m;
	cout << "Input the size of the Array >> ";
	cin >> m;
	int *B = new int[m];

	cout << "# Quicksort" << endl;
	cout << "Given array is" << endl;
	for (int i = 0; i < m; i++)
	{
		B[i] = rand() % (2 * m);
		cout << B[i] << " ";
	}
	cout << endl << endl;
	quicksort(B, 0, m - 1);
	cout << "Sorted array is " << endl;
	for (int i = 0; i < m; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	return 0;
}