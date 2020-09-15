#include <iostream> 
#include "Hash.cpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>
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
	const char *c = "Dickens_Oliver_1839.tokens.txt";
	Hash h; h.Open(c);
	double oldtime = getdtime();
	string str;

	srand((unsigned int)time(NULL));
	for (int j = MAX; j <= 10000000; j = MAX * 10)
	{
		for (int i = 0; i < j; i++)
		{
			str += getRandom();
			h.Search(str.c_str());
		}
		cout << "N= " << j << ", Hash" << ", ";
		cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
	}
	return 1;
}