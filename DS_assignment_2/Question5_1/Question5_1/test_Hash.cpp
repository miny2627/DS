#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Hash.cpp"
using namespace std;

int main()
{
	Hash h;
	h.Create(10);
	h.Insert("Apple"); h.Insert("Banana");
	h.Insert("Ca"); h.Insert("Drink");
	h.Insert("Empty"); h.Insert("Function");

	h.print(); cout << endl;
	
	h.Delete("Empty"); h.print(); cout << endl;
	
	h.Search("Ca");
	h.Update("Apple");

	return 0;
}