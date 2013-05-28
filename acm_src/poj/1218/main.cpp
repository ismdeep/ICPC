/*
 * Project     : 1218
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep 15 08:53:47 2012 
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

#define MAXN 1000

#define OPEN true
#define CLOSED false

int n;

bool door[MAXN];

void show_door_status()
{
	for (int i = 1; i <= n; i++)
	{
		if (door[i] == OPEN)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	cout << endl;
}

void init_door()
{
	for (int i = 0; i < MAXN; i++)
	{
		door[i] = CLOSED;
	}
}

void change_status(int index)
{
	for (int j = index; j <= n; j += index)
	{
		if (door[j] == OPEN)
		{
			door[j] = CLOSED;
		}
		else
		{
			door[j] = OPEN;
		}
	}
#ifdef _DEBUG_
	show_door_status();
#endif
}

int count_open_door()
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (door[i] == OPEN)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		init_door();
#ifdef _DEBUG_
		show_door_status();
#endif
		for (int i = 1; i <= n; i++)
		{
			change_status(i);
		}
		cout << count_open_door() << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

