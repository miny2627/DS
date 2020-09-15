#include <iostream> 
#include "BST.cpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <sys/time.h>
#include <unistd.h> 
#define MAX 100000
using namespace std;

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;

	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char getRandom()
{
	return alphanum[rand() % stringLength];
}

int main(int argc, char **argv)
{
	ifstream in("Dickens_Oliver_1839.tokens.txt");
	Nptr T = NULL, n = NULL;
	string s;
	vector<string> v;
	double oldtime = getdtime();
	string str;

	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> s;
			v.push_back(s);
		}
	}
	string *a = new string[v.size()];

	for (int i = 0; i < v.size(); i++)
	{
		a[i] = v[i];
		T = Insert(T, a[i].c_str());
	}

	srand((unsigned int)time(NULL));
	for (int j = MAX; j <= 10000000; j = MAX * 10)
	{
		for (int i = 0; i < j; i++)
		{
			str += getRandom();
			n = Search(T, str.c_str());
		}
		cout << "N= " << j << ", BST" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
	}
	return 1;
}