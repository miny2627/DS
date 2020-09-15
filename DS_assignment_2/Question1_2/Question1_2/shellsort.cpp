#include "shellsort.h"

inline void insertionsort(int *A, int size, int start, int h)
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

inline void shellsort(int *A, int size, int K)
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
