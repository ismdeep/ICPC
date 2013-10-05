/* 
 * Project Name : 1946
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Sat Oct  5 09:13:24 2013 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

#define MAXN 200000


bool is_prime[MAXN];

int prime[MAXN];
int __index;

void make_is_prime_map ()
{
	for (int i = 0; i < MAXN; i++)
	{
		is_prime[i] = true;
	}
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i * i < MAXN; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j < MAXN; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	// ---- fcuk....
	for (int i = 0; i < MAXN; i++)
	{
		if (is_prime[i])
		{
			__index++;
			prime[__index] = i;
		}
	}
}

int count_prime ()
{
	int count = 0;
	for (int i = 0; i < MAXN; i++)
	{
		if (is_prime[i])
		{
			count++;
		}
	}
	return count;
}

int main () 
{
	make_is_prime_map ();
	int n;
	while (cin >> n)
	{
		cout << prime[n] << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

