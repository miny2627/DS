#include <iostream>
#include "DoublyListP.h"
using namespace std;

int main()
{
	listClass list;
	list.Insert(1, 10); list.Insert(2, 20);
	list.Insert(3, 30); list.Insert(4, 40);
	list.Insert(5, 50); list.print();

	list.Insert(3, 60); list.Insert(1, 70);
	list.print(); list.Delete(3);
	list.print(); list.Delete(1);
	list.print(); int item;
	list.Retrieve(0, item); list.Retrieve(2, item);

	cout << "Å©±â " << list.Length() << endl;

	return 0;
}
