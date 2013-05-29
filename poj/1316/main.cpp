/*
 * Project     : 1316
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 13:26:13 2012 
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

bool self_num[MAXN];

int cal_digit_sum(int num)
{
	int tmp;
	tmp = num;
	while (num)
	{
		tmp += (num % 10);
		num /= 10;
	}
	return tmp;
}

void make_self_num_map()
{
	// init for self_num[]
	for (int i = 0; i < MAXN; i++)
	{
		self_num[i] = true;
	}
	//
	for (int i = 1; i < MAXN; i++)
	{
		if (self_num[i] == true)
		{
			int index = cal_digit_sum(i);
			while (index < MAXN)
			{
				self_num[index] = false;
				index = cal_digit_sum(index);
			}
		}
	}
}

void show_self_num_map()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (self_num[i] == true)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{
	make_self_num_map();
	show_self_num_map();
	return 0;
}

// end 
// iCoding@CodeLab
//

