#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
	double sum = 0.0;
	double sa;
	for (int i = 0; i < 12; i++)
	{
		cin >> sa;
		sum += sa;
	}
	sum /= (double)12;
	printf ("￥%.2lf\n", sum);
	return 0;
}


