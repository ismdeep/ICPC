/*
 * Project     : 2739
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 20:20:08 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
// #include <algorithm>
using namespace std;

#define MAXN 11000

typedef unsigned long long int longint;

bool prime[MAXN];

int count[MAXN];

void make_prime_map()
{
	// init for prime
	for (int i = 0; i < MAXN; i++)
	{
		prime[i] = true;
	}
	for (int i = 2; i * i < MAXN; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j < MAXN; j += i)
			{
				prime[j] = false;
			}
		}
	}
	prime[0] = false;
	prime[1] = false;
}

void make_count_map()
{
	// init count[]
	for (int i = 0; i < MAXN; i++)
	{
		count[i] = 0;
	}
	// start make map of count[]
	for (int i = 2; i < MAXN; i++)
	{
		if (prime[i])
		{
			int sum = i;
			count[sum]++;
			for (int j = i + 1; sum < MAXN; j++)
			{
				if (prime[j])
				{
					sum += j;
					if (sum < MAXN)
					{
						count[sum]++;
					}
				}
			}
		}
	}
}

int main()
{
	make_prime_map();
	make_count_map();
	int num;
	while (cin >> num && num)
	{
		cout << count[num] << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

