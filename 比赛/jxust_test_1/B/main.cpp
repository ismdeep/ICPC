/*
 * Project     : B
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Oct 19 23:06:12 2012 
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

// #define _ISM_DEBUG_

#ifndef MAXN
#define MAXN 200000
#endif

int iData[MAXN];
int left_sum [MAXN];
int right_sum [MAXN];
int n;

int main()
{
    while (scanf ("%d", &n) != EOF)
    {
	// input data[]
	for (int i = 0; i < n; i++)
	{
	    scanf ("%d", &iData[i]);
	}
	// get sum from left to right
	left_sum[0] = iData[0];
	for (int i = 1; i < n; i++)
	{
	    left_sum[i] = left_sum[i-1] + iData[i];
	}
	#ifdef _ISM_DEBUG_
	for (int i = 0; i < n; i++)
	{
	    cout << left_sum[i] << " ";
	}
	cout << endl;
	#endif
	// get sum from right to left
	right_sum[n-1] = iData[n-1];
	for (int i = n - 2; i >= 0; i--)
	{
	    right_sum[i] = right_sum[i+1] + iData[i];
	}
#ifdef _ISM_DEBUG_
	for (int i = 0; i < n; i++)
	{
	    cout << right_sum[i] << " ";
	}
	cout << endl;
#endif
	// get index;
	int index;
	bool found = false;
	for (int i = 0; !found && i < n; i++)
	{
	    if (left_sum[i] >= right_sum[i])
	    {
		index = i;
		found = true;
	    }
	}
	if (left_sum[index] != right_sum[index])
	{
	    cout << index << " " << n - index << endl;
	}
	else
	{
	    cout << index + 1 << " " << n - index - 1 << endl;
	}
    }
    return 0;
}

// end 
// iCoding@CodeLab
//
