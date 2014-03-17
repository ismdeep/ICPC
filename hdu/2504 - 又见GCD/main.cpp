/* 
 * Project Name : 2504
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Nov 28 22:43:58 2013 
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

bool is_prime (int n)
{
	if (n <= 1) return false;
	int sq = sqrt ((double)n+0.00001);
	bool flag = true;
	for (int i = 2; flag && i <= sq; i++)
	{
		if (0 == n % i)
		{
			flag = false;
		}
	}
	return flag;
}

int get_least_prime (int n)
{
	bool found = false;
	int re;
	for (int i = 2;!found ;i++)
	{
		if (n % i != 0)
		{
			if (is_prime(i))
			{
				re = i;
				found = true;
			}
		}
	}
	return re;
}

int main () 
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		a /= b;
		b = b * get_least_prime (a);
		cout << b << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

