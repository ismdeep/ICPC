/*
 * Project     : A
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Wed Sep 26 19:37:39 2012 
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

#define COMMON_YEAR 0
#define LEAP_YEAR 1

int month_count[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool is_legal_day (int date)
{
	int year;
	int month;
	int day;
	day   = date % 100;
	date /= 100;
	month = date % 100;
	year  = date / 100;
	bool yes = true;
	int year_flag;
	if (year == 1988)
	{
		year_flag = LEAP_YEAR;
	}
	else
	{
		year_flag = COMMON_YEAR;
	}
	if (month >= 1 && month <= 12)
	{
		if (day >= 1 && day <= month_count[year_flag][month])
		{
		}
		else
		{
			yes = false;
		}
	}
	else
	{
		yes = false;
	}
	return yes;
}

bool is_prime (int num)
{
	int stop = sqrt ((double)num);
	bool yes = true;
	for (int i = 2; yes && i <= stop; i++)
	{
		if (num % i == 0)
		{
			yes = false;
		}
	}
	return yes;
}

int main()
{
	int day;
	for (int day = 19880101; day <= 19891231; day++)
	{
		if (is_legal_day(day) && is_prime(day))
		{
			cout << day << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

