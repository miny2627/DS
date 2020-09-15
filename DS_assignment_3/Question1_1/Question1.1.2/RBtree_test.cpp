#include <iostream>
#include <string>
#include <assert.h>
#include "RBtree.cpp"
using namespace std;

int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);
	insert(100);
	RBPrettyPrint("", root, false);

	return 0;
}