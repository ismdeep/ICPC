/*
 * Project     : 2593
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 14:10:31 2012 
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

#define _DEBUG_
#define MAXN 110000
typedef long long int longint;
/////////////////////////////////////////////////////////////////////
// data section
longint data[MAXN];
int n;
longint max_sum_left[MAXN];
longint max_sum_right[MAXN];
/////////////////////////////////////////////////////////////////////
// procedure
void input_data()
{
	for (int i = 0; i < n; i++)
	{
		scanf ("%lld", &data[i]);
	}
}

void dp_from_left()
{
	max_sum_left[0] = data[0];
	for (int i = 1; i < n; i++)
	{
		max_sum_left[i] = (max_sum_left[i-1] > 0) ? max_sum_left[i-1] + data[i] : data[i];
	}
	for (int i = 1; i < n; i++)
	{
		max_sum_left[i] = (max_sum_left[i-1] > max_sum_left[i]) ? max_sum_left[i-1] : max_sum_left[i];
	}
}

void dp_from_right()
{
	max_sum_right[n-1] = data[n-1];
	for (int i = n - 2; i >= 0; i--)
	{
		max_sum_right[i] = (max_sum_right[i+1] > 0) ? max_sum_right[i+1] + data[i] : data[i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		max_sum_right[i] = (max_sum_right[i+1] > max_sum_right[i]) ?max_sum_right[i+1] : max_sum_right[i];
	}
}

void cal_max()
{
	longint max = max_sum_left[0] + max_sum_right[1];
	for (int i = 1; i <= n - 2; i++)
	{
		max = (max_sum_left[i] + max_sum_right[i+1] > max)
			? max_sum_left[i] + max_sum_right[i+1]
			: max;
	}
	printf ("%lld\n", max);
}

int main()
{
	while (scanf ("%d", &n) != EOF && n)
	{
		input_data();
		dp_from_left();
		dp_from_right();
		cal_max();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

