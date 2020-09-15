#include <iostream>
#include <string>
#include "genericQueueDL.h"
#include "genericQueueDL.cpp"
using namespace std;

int main()
{
	Queue<int> q1;
	q1.insert(10); q1.insert(20); q1.insert(30);
	q1.insert(40); q1.insert(50); q1.insert(60);
	q1.display();

	q1.remove(); int item;
	q1.GetFront(item); q1.Get(2, item);
	q1.display(); cout << endl;

	Queue<double> q2;
	q2.insert(0.01); q2.insert(0.02); q2.insert(0.03);
	q2.insert(0.04); q2.insert(0.05); q2.insert(0.06);
	q2.display();

	q2.remove(); double d;
	q2.GetFront(d); q2.Get(5, d);
	q2.display(); cout << endl;

	Queue<string> q3; q3.remove();
	q3.insert("Apple"); q3.insert("Banana"); q3.insert("Car");
	q3.insert("Double"); q3.insert("Empty"); q3.insert("Front");
	q3.display();

	q3.remove(); string s;
	q3.GetFront(s); q3.Get(0, s);
	q3.display();

	return 0;
}