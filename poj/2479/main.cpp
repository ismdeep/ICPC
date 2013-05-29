/*
 * Project     : 2479
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 13:00:53 2012 
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

// #define _DEBUG_

typedef long long int longint;

#define MAXN 55000

longint a[MAXN];
int n;

longint max_from_left[MAXN];
longint max_from_right[MAXN];

void input_a_array()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
}

////////////////
// debug code
void show_a_array()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


void cal_max_from_left()
{
	max_from_left[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max_from_left[i-1] > 0)
		{
			max_from_left[i] = a[i] + max_from_left[i-1];
		}
		else
		{
			max_from_left[i] = a[i];
		}
	}
	longint max = max_from_left[0];
	for (int i = 1; i < n; i++)
	{
		if (max_from_left[i] > max)
		{
			max = max_from_left[i];
		}
		else
		{
			max_from_left[i] = max;
		}
	}
#ifdef _DEBUG_
	for (int i = 0; i < n; i++)
	{
		cout << max_from_left[i] << " ";
	}
	cout << endl;
#endif
}

void cal_max_from_right()
{
	max_from_right[n-1] = a[n-1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (max_from_right[i+1] > 0)
		{
			max_from_right[i] = a[i] + max_from_right[i+1];
		}
		else
		{
			max_from_right[i] = a[i];
		}
	}
	longint max = max_from_right[n-1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (max_from_right[i] > max)
		{
			max = max_from_right[i];
		}
		else
		{
			max_from_right[i] = max;
		}
	}
#ifdef _DEBUG_
	for (int i = 0; i < n; i++)
	{
		cout << max_from_right[i] << " ";
	}
	cout << endl;
#endif
}

void cal_result()
{
	longint max = max_from_left[0] + max_from_right[1];
	for (int i = 1; i <= n - 2; i++)
	{
		max = (max_from_left[i] + max_from_right[i+1] > max)
			? max_from_left[i] + max_from_right[i+1]
			: max;
	}
	printf("%lld\n", max);
}

/////////////////////////////////////////////////////////////////////

int main()
{
	int case_count;
	scanf("%d", &case_count);
	while (case_count--)
	{
		input_a_array();
#ifdef _DEBUG_
		show_a_array();
#endif
		cal_max_from_left();
		cal_max_from_right();
		cal_result();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

