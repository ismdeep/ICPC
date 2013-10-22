#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main ()
{
	int n;
	while (cin >> n)
	{
		double sum = 0.0;
		for (int i = 1; i <= n; i++)
		{
			sum += ((double)1/(double)i);
		}
		printf ("%.6lf \n", sum);
	}
	return 0;
}


