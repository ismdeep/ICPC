/*
 * Project     : Prime-Factors
 * File        : main.cpp
 * Author      : ismdeep
 *
 * Date & Time : Wed Mar 12 20:21:56 2014 
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


int main()
{
	longint n;
	while (scanf ("%lld", &n), n)
	{
		cout << n << " = ";
		bool flag = false;
		if (n < 0)
		{
			cout << "-1";
			flag = true;
			n = 0 - n;
		}
		// ------ 
		for (int i = 2; i * i <= n; i++)
		{
			while (n % i == 0)
			{
				if (flag)
				{
					cout << " x ";
				}
				cout << i;
				n /= i;
				flag = true;
			}
		}
		if (n != 1)
		{
			if (flag)
			{
				cout << " x ";
			}
			cout << n;
		}
		cout << endl;
	}
	return 0;
}

// end 
// ismdeep@LeMoX
//

