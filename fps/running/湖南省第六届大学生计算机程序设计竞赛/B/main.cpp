/*
 * Project     : B
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 21:04:30 2012 
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

#define plus true
#define minus false

typedef long long int longint;

bool judge(string msg)
{
	int a, b, c;
	int index = 0;
	a = 0;
	while (msg[index] >= '0' && msg[index] <= '9')
	{
		a *= 10;
		a += (msg[index] - '0');
		index++;
	}
	bool sign;
	if (msg[index] == '+')
	{
		sign = plus;
	}
	else
	{
		sign = minus;
	}
	index++;
	b = 0;
	while (msg[index] >= '0' && msg[index] <= '9')
	{
		b *= 10;
		b += (msg[index] - '0');
		index++;
	}
	index++;
	if (msg[index] == '?')
	{
		return false;
	}
	else
	{
		c = 0;
		while (msg[index] >= '0' && msg[index] <= '9')
		{
			c *= 10;
			c += (msg[index] - '0');
			index++;
		}
		if (sign == plus)
		{
			if (a + b == c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (a - b == c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int main()
{
	int count = 0;
	string str_msg;
	while (cin >> str_msg)
	{
		// cout << str_msg << " ";
		if (judge(str_msg))
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}

// end 
// iCoding@CodeLab
//

