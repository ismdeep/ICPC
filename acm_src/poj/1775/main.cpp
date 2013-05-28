/*
 * Project     : 1775
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 16:37:01 2012 
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

// 1000000

// #define _DEBUG_

typedef unsigned long long int longint;

#define MAXN 9

longint iMap[MAXN+1];

void make_map()
{
	longint tmp = 1;
	iMap[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		tmp *= i;
		iMap[i] = tmp;
	}
#ifdef _DEBUG_
	for (int i = 1; i <= MAXN; i++)
	{
		cout << iMap[i] << endl;
	}
#endif
}

bool judge(longint num)
{
	if (num == 0)
	{
		return false;
	}
	for (int i = 9; i >= 0; i--)
	{
		if (num >= iMap[i])
		{
			num = num - iMap[i];
		}
	}
	if (num == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string yes = "YES";
	string no  = "NO";
	make_map();
	int num;
	while (cin >> num && num >= 0)
	{
		bool judge_value = judge (num);
		if (judge_value)
		{
			cout << yes << endl;
		}
		else
		{
			cout << no  << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

