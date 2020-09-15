#include <iostream> 
#include <iomanip>
#include <time.h>
#include <sys/time.h>
#include <unistd.h> 
#include "shellsort.cpp"
#define MAX 1000
using namespace std;

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;

	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main(int argc, char **argv)
{
	int x, a[1000000];
	int K = 1;
	double oldtime = getdtime();

	srand((unsigned int)time(NULL));
	for (int j = MAX; j <= 1000000; j = MAX * 10)
	{
		for (int i = 0; i < j; i++)
		{
			x = rand() % 50;
			a[i] = x;
		}
		for (int k = K; k < 4; k++)
		{
			shellsort(a, j, k);
			for (int l = 0; l < j; l++)
			{
				usleep(j);
			}
			double elapsed_time = getdtime() - oldtime;

			cout << "N= " << j << ", K= " << k << ", ";
			cerr << "elapsed_time: " << elapsed_time << "sec" << endl;
		}
	}
	
	return 1;
}