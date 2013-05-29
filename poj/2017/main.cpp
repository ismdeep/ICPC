/*
 * Project     : 2017
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Wed Sep 12 17:29:22 2012 
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

typedef long long int longint;

#define MAXN 100

int value[MAXN];
int i_time[MAXN];
int n;

void input_data()
{
	i_time[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i] >> i_time[i];
	}
}

void cal_result()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (value[i] * (i_time[i] - i_time[i-1]));
	}
	cout << ans << " miles" << endl;
}


int main()
{
	while (cin >> n && n != -1)
	{
		input_data();
		cal_result();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

