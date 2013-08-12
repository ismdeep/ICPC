/*
 * Project     : 1333
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 20:28:29 2012 
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

bool cmp(int a, int b)
{
	return (a > b) ? true : false ;
}

int main()
{
	int iT;
	scanf("%d", &iT);
	while (iT--)
	{
		int n;
		scanf("%d", &n);
		int iMax[3];
		memset(iMax, 0, sizeof(iMax));
		int tmp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			iMax[2] = tmp;
			sort(iMax, iMax + 3, cmp);
		}
		printf("%d\n", iMax[1]);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

