/*
 * Project     : 1321v2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 16:44:32 2012 
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

int main()
{
	int n, m;
	while (cin >> n >> m && n + m)
	{
		double dp[2100];
		for (int i = 0; i < m; i++)
		{
			dp[i] = 0;
		}
		dp[m] = pow(0.5, m);
		for (int i = m + 1; i <= n; i++)
		{
			dp[i] = dp[i-1] + (1 - dp[i-m-1]) * pow(0.5, m+1);
		}
		printf("%.2lf\n", dp[n]);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

