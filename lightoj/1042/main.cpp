/*
 * Project     : 1042
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Aug 30 14:03:49 2012 
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

typedef long long int longint;

#define MAXN 100

int iMap[MAXN];

void debug()
{
	cout << "--debug msg--" << endl;
}

void set_map(int num)
{
	int index = -1;
	while (num)
	{
		index++;
		if (num % 2 == 1)
		{
			iMap[index] = 1;
		}
		else
		{
			iMap[index] = 0;
		}
		num /= 2;
	}
}

void init_map()
{
	for (int i = 0; i < MAXN; i++)
	{
		iMap[i] = 0;
	}
}

void shift_map_up()
{
	// kernel of this problem
	int count  = 0;
	bool found = false;
	int index = -1;
	for (int i = 0; !found && i < MAXN; i++)
	{
		if (iMap[i] == 1)
		{
			count++;
		}
		else
		{
			if (count > 0)
			{
				found = true;
				index = i;
			}
		}
	}
	iMap[index] = 1;
	for (int i = 0; i < index; i++)
	{
		iMap[i] = 0;
	}
	count--;
	for (int i = 0; i < count; i++)
	{
		iMap[i] = 1;
	}
}

int get_value_map()
{
	int num;
	num = 0;
	for (int i = MAXN - 1; i >= 0; i--)
	{
		num *= 2;
		num += iMap[i];
	}
	return num;
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		int num;
		cin >> num;
		init_map();
		set_map(num);
		shift_map_up();
		num = get_value_map();
		cout << num << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

