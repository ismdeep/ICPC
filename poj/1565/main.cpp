/*
 * Project     : 1565
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep 22 12:51:32 2012 
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

#define _DEBUG_
#define MAXN 32
typedef unsigned long long int longint;

longint power2[MAXN+1];

void make_power2_map ()
{
	power2[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		power2[i] = power2[i-1] * 2;
	}
	// - 1 for all power2[]
	for (int i = 0; i <= MAXN; i++)
	{
		power2[i]--;
	}
}

longint translate_skew_binary (string str_skew)
{
	longint sum = 0;
	int top = str_skew.length() - 1;
	for (int i = 0; i <= top; i++)
	{
		longint tmp = power2[top-i+1] * (str_skew[i] - '0');
		sum += tmp;
	}
	return sum;
}

int main()
{
	make_power2_map ();
	string str_stew;
	while (cin >> str_stew && str_stew != "0")
	{
		cout << translate_skew_binary (str_stew) << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

