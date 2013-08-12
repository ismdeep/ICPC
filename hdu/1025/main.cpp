/*
 * Project     : 1025
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Aug 25 15:34:29 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// data section
#define MAXN 500000

int iMap[MAXN];
int iCount[MAXN];
int n;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// procedure

void init_map()
{
	memset(iCount, 0, sizeof(iCount));
	memset(iMap , 0, sizeof(iMap));
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		iMap[x] = y;
	}
}

void dynamic_programming()
{
	for (int i = 1; i <= n; i++)
	{
		int max_count = 0;
		for (int j = 1; j < i; j++)
		{
			if (iMap[j] < iMap[i] && iCount[j] > max_count)
			{
				max_count = iCount[j];
			}
		}
		iCount[i] = max_count + 1;
	}
}

void show_result(int case_id)
{
	int max_count = iCount[1];
	for (int i = 2; i <= n; i++)
	{
		if (iCount[i] > max_count)
		{
			max_count = iCount[i];
		}
	}
	printf("Case %d:\n", case_id);
	printf("My king, at most %d road can be built.\n", max_count);
}

int main()
{
	int case_count = 0;
	while (scanf("%d", &n) != EOF)
	{
		case_count++;
		init_map();
		dynamic_programming();
		show_result(case_count);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

