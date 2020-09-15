#include <iostream>
#include <string>
#include "GenericDoublyListP.h"
#include "GenericDoublyListP.cpp"

using namespace std;

int main()
{
	listClass<int> list1;
	listClass<double> list2;
	listClass<string> list3;

	list1.Insert(1, 10); list1.Insert(2, 20);
	list1.Insert(3, 30); list1.Insert(4, 40);
	list1.Insert(5, 50);
	list1.print();

	list1.Insert(3, 60); list1.Insert(1, 70);
	list1.print();

	list1.Delete(3);
	list1.print();
	int item;
	list1.Retrieve(2, item);

	cout << "크기 " << list1.Length() << endl;
	cout << endl;

	list2.Insert(1, 0.1); list2.Insert(2, 0.2); list2.Insert(3, 0.3);
	list2.Insert(4, 0.4); list2.Insert(5, 0.5); list2.print();

	list2.Insert(3, 0.6); list2.Insert(1, 0.7); list2.print();
	list2.Delete(3); list2.print(); double d; list2.Retrieve(2, d);
	cout << "크기 " << list2.Length() << endl;
	cout << endl;

	list3.Insert(1, "Apple"); list3.Insert(2, "Banana"); list3.Insert(3, "Car");
	list3.Insert(4, "Double"); list3.Insert(5, "Empty"); list3.print();

	list3.Insert(3, "Full"); list3.Insert(1, "Group"); list3.print();
	list3.Delete(0); list3.print(); string s; list3.Retrieve(2, s);
	cout << "크기 " << list3.Length() << endl;

	return 0;
}