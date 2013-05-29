/*
 * Project     : 1562
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep 22 12:28:40 2012 
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

// #define _DEBUG_
#define MAXN 200
typedef unsigned long long int longint;

char iMap[MAXN][MAXN];
int n, m;
int count_block;


void input_data_iMap ()
{
	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			iMap[i][j] = line[j];
		}
	}
}

void show_data_iMap ()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << iMap[i][j];
		}
		cout << endl;
	}
}

bool can_go (int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void cover_block (int x, int y)
{
	for (int dir_x = -1; dir_x <= 1; dir_x++)
	{
		for (int dir_y = -1; dir_y <= 1; dir_y++)
		{
			if (can_go (x + dir_x , y + dir_y))
			{
				if (iMap[x + dir_x][y + dir_y] == '@')
				{
					iMap[x + dir_x][y + dir_y] = '*';
					cover_block (x + dir_x, y + dir_y);
				}
			}
		}
	}
}

void scan ()
{
	count_block = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (iMap[i][j] == '@')
			{
				iMap[i][j] = '*';
				count_block++;
				cover_block (i, j);
			}
		}
	}
}

void show_result ()
{
	printf ("%d\n", count_block);
}

int main()
{
	while (scanf ("%d%d", &n, &m) != EOF && n + m)
	{
		input_data_iMap();
#ifdef _DEBUG_
		show_data_iMap();
#endif
		scan();
		show_result ();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

