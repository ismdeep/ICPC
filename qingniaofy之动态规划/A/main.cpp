/*
 * Project     : A
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : 2012/8/22 16:32
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

/************************************************************/
/* data */
#define MAXN 110
int iMap[MAXN][MAXN];
int n;
/************************************************************/
/* procedure */
void init_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &iMap[i][j]);
		}
	}
}

void dynamic_programming()
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (iMap[i+1][j+1] > iMap[i+1][j])
			{
				iMap[i][j] += iMap[i+1][j+1];
			}
			else
			{
				iMap[i][j] += iMap[i+1][j];
			}
		}
	}
}

void show_result()
{
	printf("%d\n", iMap[0][0]);
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init_map();
		dynamic_programming();
		show_result();
	}
	//
	//
	return 0;
}

// end 
// iCoding@CodeLab
//

