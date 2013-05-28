/*
 * Project     : 1006v2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep  9 15:14:24 2012 
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
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;
typedef unsigned long long int longint;
#define INF 0X3FFFFFFF
#define MAXN 200
int n;
longint ans[MAXN][MAXN];
longint data[MAXN];

void show_ans_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

longint cal_ans(int start, int end)
{
	longint min = INF;
	longint tmp;
	int a, b, c, d;
	a = start;
	d = end;
	for (b = start; b < end; b++)
	{
		c = b + 1;
		tmp  = ans[c][d];
		tmp += ans[a][b];
		for (int i = 0; i <= (d-c); i++)
		{
			for (int j = a; j <= b; j++)
			{
				tmp += data[j];
			}
		}
		if (min > tmp)
		{
			min = tmp;
		}
		/////////////////////////////////////////////////////////////
		tmp  = ans[a][b];
		tmp += ans[c][d];
		for (int i = 0; i <= (b-a); i++)
		{
			for (int j = c; j <= d; j++)
			{
				tmp += data[j];
			}
		}
		if (min > tmp)
		{
			min = tmp;
		}
	}
	return min;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int case_count = 1; case_count <= t; case_count++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &data[i]);
		}
		// init
		memset(ans, 0, sizeof(ans));
		// to that
		for (int j = 1; j < n; j++)
		{
			int start;
			int end;
			start = 0; end = j;
			for (end = j; end < n; end++)
			{
				//
				ans[start][end] = cal_ans(start, end);
				//
				//
				//
				// done 
				start++;
			}
		}
		cout << "Case #" << case_count << ": ";
		cout << ans[0][n-1] << endl;
		show_ans_map();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

