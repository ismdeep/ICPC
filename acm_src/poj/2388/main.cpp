/*
 * Project     : 2388
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 14:23:34 2012 
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

#define MAXN 11000

int data[MAXN];

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	sort(data, data + n, cmp);
	printf("%d\n", data[n/2]);
	return 0;
}

// end 
// iCoding@CodeLab
//

