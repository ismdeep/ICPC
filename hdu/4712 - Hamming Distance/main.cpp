/*
 * FUCK THIS PROBLEM.
 *
 * Author: ismdeep
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
using namespace std;

#define MAXN 200000

//--- data section
int a[MAXN];
int n;

int cal_bin (int value)
{
	int count = 0;
	while (value)
	{
		count += (value % 2);
		value >>= 1;
	}
	return count;
}




int main ()
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf ("%X", &a[i]);
		}
		int min_countor;
		min_countor = cal_bin (a[0] ^ a[1]);
		int count_time = 1000000;
		while (count_time--)
		{
			int x_index;
			int y_index;
			x_index = rand () % n;
			y_index = rand () % n;
			if (x_index != y_index)
			{
				int tmp_countor = 
					cal_bin (a[x_index] ^ a[y_index]);
				if (tmp_countor < min_countor)
				{
					min_countor = tmp_countor;
				}
			}
		}
		printf ("%d\n", min_countor);
	}
	return 0;
}



