/*
 * Project     : 2429
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 11:38:35 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef unsigned long long longint;

longint gcd_num, lcm_num;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// gcd 
longint gcd(longint a, longint b)
{
	longint tmp;
	while (b)
	{
		tmp = a % b;
		a   = b;
		b   = tmp;
	}
	return a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// inverse gcd lcm
void inverse_gcd_lcm()
{
	longint mul_num = lcm_num / gcd_num;
	bool found = false;
	for (longint a = sqrt((double)mul_num); !found && a >= 1; a--)
	{
		if (mul_num % a == 0)
		{
			longint b = mul_num / a;
			if (gcd(a, b) == 1)
			{
				// oh yeah ~~~ I got it.....
				cout << a * gcd_num << " " << b * gcd_num << endl;
				found = true;
			}
		}
	}
}

int main()
{
	while (cin >> gcd_num >> lcm_num)
	{
		inverse_gcd_lcm();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

