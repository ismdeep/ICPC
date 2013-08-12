/*
 * Project     : 1002
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep  9 12:16:36 2012 
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

typedef unsigned long long int longint;

longint gcd(longint a, longint b)
{
	while (b)
	{
		longint tmp;
		tmp = a % b;
		a   = b;
		b   = tmp;
	}
	return a;
}

void show_test()
{
	int max = 30100;
	int current = 0;
	for (int num = 1; num <= max; num++)
	{
		cout << num << " - ";
		int count = 0;
		for (int i = 1; i <= num; i++)
		{
			if (num % i != 0 && gcd(i, num) != 1)
			{
				count++;
			}
		}
		if (count % 2 == 1)
		{
			current++;
		}
		cout << current << endl;
	}
}

int main()
{
	show_test();
	int T;
	cin >> T;
	while (T--)
	{
		longint start, end;
		cin >> start >> end;
		//
		//
		//
		//
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

