#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int iData[1100];

int main()
{
    int n;
    while (cin >> n)
    {
	for (int i = 0; i < n; i++)
	{
	    cin >> iData[i];
	}
	sort (iData, iData + n);
	double sum = 0.0;
	for (int i = 1; i < n - 1; i++)
	{
	    sum += (double)iData[i];
	}
	sum /= (n-2);
	printf ("%.2f\n", sum);
    }
    return 0;
}
//end;
