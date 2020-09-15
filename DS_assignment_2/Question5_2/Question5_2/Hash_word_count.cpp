#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Hash.cpp"
using namespace std;

int main()
{
	const char *c1 = "The-Road-Not-Taken.tokens.txt";
	const char *c2 = "Dickens_Oliver_1839.tokens.txt";
	const char *s1 = "The-Road-Not-Taken.hash.txt";
	const char *s2 = "Dickens_Oliver_1839.hash.txt";

	Hash h;
	h.Open(c1); h.Save(s1);
	h.Open(c2); h.Save(s2);
	
	return 0;
}