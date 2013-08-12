/*
 * Project     : 1321
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 15:12:36 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef unsigned long long int longint;

double possible[2100][2100];

double half_pos_pow[2100];

void make_half_pos_pow()
{
	half_pos_pow[0] = 1.0;
	for (int i = 1; i < 2100; i++)
	{
		half_pos_pow[i] = half_pos_pow[i-1] * (double)0.5;
	}
}

double get_possible(int n, int m)
{
	if ((double)fabs(possible[n][m] - (double)0.0) >= 1E-07)
	{
		return possible[n][m];
	}
	else
	{
	}
	double double_ans;
}

void init_possible()
{
	for (int i = 0; i < 2100; i++)
	{
		for (int j = 0; j < 2100; j++)
		{
			possible[i][j] = 0.0;
		}
	}
}

void make_possible()
{
	for (int i = 1; i < 2100; i++)
	{
		for (int j = 1; j < 2100; j++)
		{
			if (i == j)
			{
				possible[i][j] = half_pos_pow[i];
			}
			else if (j == 1)
			{
				possible[i][j] = (double)i * half_pos_pow[i];
			}
			else if (i > j)
			{
				possible[i][j]  = possible[i-1][j] + possible[i-1][j-1];
				possible[i][j] *= (double)0.5;
			}
			else
			{
				// doing nothing
			}
		}
	}
}

int main()
{
	//
	//
	// init 
	make_half_pos_pow();
	init_possible();
	// 
	// make possible
	make_possible();
	//
	int n, m;
	while (cin >> n >> m && n + m)
	{
		double ans = 0.0;
		for (int i = m; i <= n; i++)
		{
			ans += possible[n][i];
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

