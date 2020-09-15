#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int BinarySearch(int A[], int start, int end, int key)
{
	
	while (start <= end)
	{ 
		int mid = start + (end - start) / 2;
		if (A[mid] < key)
		{
			start = mid + 1;
		}
		else if (A[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
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
	int end = n-1;
	int key;

	cout << "숫자를 입력하세요" << endl;
	cin >> key;

	int index = BinarySearch(data, start, end, key);

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