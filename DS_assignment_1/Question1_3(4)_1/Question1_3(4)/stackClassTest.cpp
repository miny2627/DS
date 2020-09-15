#include <iostream>
#include <string>
#include "genericStackDL.h"
#include "genericStackDL.cpp"
using namespace std;

int main()
{
	stackClass<int> s;
	s.Push(1); s.Push(2); s.Push(3);
	s.Push(4); s.Push(5); s.Print();

	int Item; s.GetTop(Item);
	s.Get(4, Item); s.Pop(); s.Print();
	s.Pop(); s.Print();
	cout << endl;

	stackClass<double> s2;
	s2.Push(0.01); s2.Push(0.02); s2.Push(0.03);
	s2.Push(0.04); s2.Push(0.05); s2.Print();

	double d; s2.GetTop(d); s2.Get(3, d);
	s2.Pop(); s2.Print();
	cout << endl;

	stackClass<string> s3;
	s3.Pop();
	s3.Push("Apple"); s3.Push("Banana"); s3.Push("Car");
	s3.Push("Double"); s3.Push("Empty"); s3.Print();

	string str; s3.GetTop(str); s3.Get(0, str);
	s3.Pop(); s3.Print();

	return 0;
}