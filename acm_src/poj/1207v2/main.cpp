/*
 * Project     : 1207v2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 15:28:03 2012 
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

int cal_length(int num)
{
	int count = 0;
	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else
		{
			num = num * 3 + 1;
		}
		count++;
	}
	return count;
}

int iMax(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		bool swap_flag = false;
		if (a > b)
		{
			int tmp;
			tmp = a;
			a   = b;
			b   = tmp;
			swap_flag = true;
		}
		int max_length = 0;
		for (int i = a; i <= b; i++)
		{
			int i_length = cal_length(i);
			max_length = iMax(max_length, i_length);
		}
		if (swap_flag == true)
		{
			int tmp;
			tmp = a;
			a   = b;
			b   = tmp;
		}
		cout << a << " " << b << " " << max_length + 1 << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

