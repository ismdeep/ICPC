/*
 * Project     : 3006
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 09:17:51 2012 
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

#define MAXN 1100000

bool is_prime[MAXN];

void make_is_prime_map()
{
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i < MAXN; i++)
	{
		is_prime[i] = true;
	}
	for (int i = 2; i * i < MAXN; i++)
	{
		if (is_prime[i] == true)
		{
			for (int j = i * i; j < MAXN; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}

int main()
{
	make_is_prime_map();
	int a, d, n;
	while (cin >> a >> d >> n && a + d + n)
	{
		if (is_prime[a] == true)
		{
			n--;
		}
		int index = a;
		while (n--)
		{
			index += d;
			while (is_prime[index] == false)
			{
				index += d;
			}
		}
		cout << index << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

