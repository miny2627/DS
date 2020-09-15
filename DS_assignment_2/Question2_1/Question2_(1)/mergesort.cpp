inline void merge(int *A, int first, int mid, int last)
{
	int first1 = first; int first2 = mid + 1;
	int last1 = mid; int last2 = last;
	int index = first1;
	int n;
	int temp[100];
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

inline void mergesort(int *A, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(A, first, mid);
		mergesort(A, mid + 1, last);
		merge(A, first, mid, last);
	}
}