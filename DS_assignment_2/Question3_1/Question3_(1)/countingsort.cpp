inline void countingsort(int *A, int size, int k)
{
	int count[50] = { 0 };
	int sorted[50];

	for (int i = 0; i < size; i++)
	{
		count[A[i]]++;
	}
	for (int i = 1; i < k; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		sorted[--count[A[i]]] = A[i];
	}
	for (int i = 0; i < size; i++)
	{
		A[i] = sorted[i];
	}

}