/* 
 * Project Name : D
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Oct 27 20:08:38 2012 
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

#define MAXN 7500

int dp_map[MAXN+1];
int coin[5] = {1, 5, 10, 25, 50};

void init_dp_map ()
{
	memset (dp_map, 0, sizeof(dp_map));
	dp_map[1] = 1;
}

void dynamic_programming ()
{
	for (int i = 1; i <= MAXN; i++)
	{
		for (
				int coin_index = 0;
				coin_index < 5;
				coin_index++
				)
		{
			if (i + coin[coin_index] <= MAXN)
			{
				dp_map[i+coin[coin_index]] += 
					dp_map[i];
			}
		}
	}
}

int main () 
{
	init_dp_map ();
	dynamic_programming ();
	int money_value;
	while (cin >> money_value)
	{
		cout << dp_map[money_value] << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

