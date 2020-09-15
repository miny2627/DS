#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <sys/time.h>
#include <unistd.h> 
#define MAX 1000
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

void shellsort(int *A, int size, int K)
{
	if (K == 1)
	{
		insertionsort(A, size, 0, 1);
	}
	else {
		for (int gap = (size / K); gap > 0; gap /= K)
		{
			if ((gap % 2) == 0)
			{
				gap++;
			}
			for (int i = 0; i < gap; i++)
			{
				insertionsort(A, size, i, gap);
			}
		}
	}

}

void quicksort(int A[], int first, int last)
{
	int i = first, j = last;
	int temp;
	int pivot = A[(first + last) / 2];

	while (i <= j)
	{
		while (A[i] < pivot) i++;
		while (A[j] > pivot) j--;
		if (i <= j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort(A, first, j);
	if (i < last)
		quicksort(A, i, last);
}

void merge(int *A, int first, int mid, int last)
{
	int first1 = first; int first2 = mid + 1;
	int last1 = mid; int last2 = last;
	int index = first1;
	int temp[MAX*10000];
	for (; (first1 <= last1) && (first2 <= last2); ++index)
	{
		if (A[first1] < A[first2])
		{
			temp[index] = A[first1];
			++first1;
		}
		else
		{
			temp[index] = A[first2];
			++first2;
		}
	}
	for (; first1 <= last1; ++first1, ++index)
	{
		temp[index] = A[first1];
	}
	for (; first2 <= last2; ++first2, ++index)
	{
		temp[index] = A[first2];
	}
	for (index = first; index <= last; ++index)
	{
		A[index] = temp[index];
	}
}

void mergesort(int *A, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(A, first, mid);
		mergesort(A, mid + 1, last);
		merge(A, first, mid, last);
	}
}

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;

	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main(int argc, char **argv)
{
	int x, a[10000000];
	double oldtime = getdtime();

	srand((unsigned int)time(NULL));
	for (int j = MAX; j <= 10000000; j = MAX * 10)
	{
		for (int i = 0; i < j; i++)
		{
			x = rand() % 50;
			a[i] = x;
		}

		shellsort(a, j, 3);
		for (int i = 0; i < j; i++)
		{
			usleep(j);
		}
		double elapsed_time = getdtime() - oldtime;

		cout << "N= " << j << ", Pratt, K= 3" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;

		for (int i = 0; i < j; i++)
		{
			usleep(j);
		}
		shellsort_sedgewick(a, j);
		cout << "N= " << j << ", Sedgewick" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;

		for (int i = 0; i < j; i++)
		{
			usleep(j);
		}
		mergesort(a, 0, j);
		cout << "N= " << j << ", Mergesort" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;

		for (int i = 0; i < j; i++)
		{
			usleep(j);
		}
		quicksort(a, 0, j);
		cout << "N= " << j << ", Quicksort" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
	}
	return 1;
}