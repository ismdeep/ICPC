/*
 * Project     : 1088
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Oct 06 15:05:33 2012 
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

#define MAXN 110

struct Block
{
	int x;
	int y;
	int height;
};

bool cmpBlock (Block a, Block b)
{
	return (a.height < b.height);
}

Block iMap[MAXN*MAXN];
int R,C;
int top;

void input_map ()
{
	top = -1;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			top++;
			int height;
			cin >> height;
			iMap[top].x = i;
			iMap[top].y = j;
			iMap[top].height = height;
		}
	}
}

void show_map ()
{
	for (int i = 0; i <= top; i++)
	{
		cout << iMap[i].x << " " << iMap[i].y << " - " << iMap[i].height << endl;
	}
}

void sort_map ()
{
	sort (iMap, iMap + top + 1, cmpBlock);
}

int main()
{
	while (cin >> R >> C)
	{
		input_map ();
		show_map ();
		cout << "------------------------------------------------" << endl;
		sort_map ();
		show_map ();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

