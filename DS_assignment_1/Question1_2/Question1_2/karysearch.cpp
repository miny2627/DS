#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int KarySearch(int A[], int k, int start, int end, int key)
{
	while (start <= end) {
		if (A[start] == key) {
			return start;
		}
		else if (A[end] == key) {
			return end;
		}
		else if (key < A[start] || key > A[end]) {
			return -1;
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				if (A[start + (end - start) * i / k] <= key && key <= A[start + ((end - start) * (i + 1) / k)]) {
					cout << start << " " << end << endl;
					start++;
					KarySearch(A, k, start + (end - start) * i / k, start + ((end - start) * (i + 1) / k), key);
					break;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ifstream read;
	read.open("input.txt");

	int num;
	vector<int> d;

	if (read.is_open())
	{
		while (read >> num)
		{
			d.push_back(num);
			read.get();
		}
	}
	else cout << "File could not be opened" << endl;

	int *data = new int[d.size()];
	for (int i = 0; i < d.size(); i++)
	{
		data[i] = d[i];
	}

	int n = d.size();
	int start = 0;
	int end = n - 1;
	int key, k;
	cout << "K와 숫자를 입력하세요 ";
	cin >> k >> key;
	if (k > n) cout << "Out of range" << endl;

	int index = KarySearch(data, k, start, end, key);

	if (index == -1)
	{
		cout << "can't find" << endl;
	}
	else
	{
		cout << "Index : " << index << endl;
	}

	return 0;
}
