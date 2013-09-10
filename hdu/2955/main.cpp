// Project name : 2955 ( Robberies ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 10:32:00 2012


#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define N 10020


struct Good
{
	int value;
	double pro;
};

Good good[N];
double max(double a, double b)
{
	return a > b ? a : b ;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double p;
		int n;
		double f[N];
		cin >> p >> n;
		int m;
		m = 0;
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> good[i].value >> good[i].pro;
			m += good[i].value;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= good[i].value; j--)
			{
				f[j]=max(f[j],f[j-good[i].value]*(1-good[i].pro));
			}
		}

		int index;
		for (int i = m; i >= 0; i--)
		{
			if (f[i] >= 1 - p)
			{
				index = i;
				break;
			}
		}
		cout << index << endl;
	}
}
// end 
// ism 

