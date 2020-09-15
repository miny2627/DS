#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#define MAX_WORD_SIZE 25
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX 100000
using namespace std;

typedef struct
{
	char word[MAX_WORD_SIZE] = { 0 };
}elt;

elt list[MAX];
int n;

int compare(elt e1, elt e2)
{
	return strcmp(e1.word, e2.word);
}

int partition(elt list[], int left, int right)
{
	elt pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do
			low++;
		while (compare(list[low], pivot) < 0);
		do
			high--;
		while (compare(list[high], pivot) > 0);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(elt list[], int left, int right)
{
	if (left < right) {
		int p = partition(list, left, right);
		quick_sort(list, left, p - 1);
		quick_sort(list, p + 1, right);
	}
}

void insert(elt e)
{
	if (n < (MAX - 1))
		list[n++] = e;
}

int main() {
	string A;
	elt e;

	ifstream in("tokens.txt");
	ofstream out("tokens.exchange_sorted.txt");

	if (in.is_open()) {
		while(!in.eof())
		{
			in >> A;
			for (int i = 0; i < A.length(); i++)
				e.word[i] = A.at(i);
			insert(e);
		}
	}
	else
	{
		cout << "Can't find the file" << endl;
		return 0;
	}
	quick_sort(list, 0, MAX);

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 20; j++)
			out << list[i].word[j];
		out << endl;
	}

	return 0;
}