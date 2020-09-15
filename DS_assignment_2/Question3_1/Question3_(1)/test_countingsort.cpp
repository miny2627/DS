#include <iostream>
#include <cstdlib>
#include <ctime>
#include "countingsort.cpp"
using namespace std;

int main()
{
	int n;
	cout << "Input the size of the Array >> ";
	cin >> n;

	if (n >= 49)
	{
		cout << "Out of Range" << endl;
		return 0;
	}

	int *A = new int[n];
	srand(time(0));
	cout << "# Countingsort" << endl;
	cout << "Given array is" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 10;
		cout << A[i] << " ";
	}
	cout << endl;

	countingsort(A, n, n + 2);
	cout << "Sorted array is" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}