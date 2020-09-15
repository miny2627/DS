inline void quicksort(int A[], int first, int last)
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