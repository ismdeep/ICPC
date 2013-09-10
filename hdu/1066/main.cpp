/*
 * Project     : 1066
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Sep 20 11:16:51 2012 
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

#define MOD 1000000
// #define _DEBUG_
typedef unsigned long long int longint;

int get_last_none_zero_digit(longint num, int& value)
{
	while (num % 10 == 0 && num != 0)
	{
		num /= 10;
	}
	num %= MOD;
	value = num;
	return num % 10;
}

int main()
{
	int max_num;
	cin >> max_num;
	int tmp_num = 1;
	for (int i = 1; i <= max_num; i++)
	{
		tmp_num *= i;
		int tmp;
		int last_none_zero_digit = get_last_none_zero_digit(tmp_num, tmp);
#ifdef _DEBUG_
		cout << i << " " << last_none_zero_digit << endl;
		cout << "--" << tmp << endl;
#endif
		cout << last_none_zero_digit << " ";
		tmp_num = tmp;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

