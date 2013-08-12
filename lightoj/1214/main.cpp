/*
 * Project     : 1214
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 14:53:43 2012 
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

#define MAXN 1000

typedef long long int longint;

const string divisible     = "divisible";
const string not_divisible = "not divisible";

class Number
{
public:
	longint a[MAXN];
	void set_value(string str_num);
	bool div_success(longint num);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Number::set_value()
void Number::set_value(string str_num)
{
	// init for a[] int classs Number
	for (int i = 0; i < MAXN; i++)
	{
		a[i] = 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (str_num[0] == '-')
	{
		for (int i = 1; i < str_num.length(); i++)
		{
			a[str_num.length() - i - 1] = str_num[i] - '0';
		}
	}
	else
	{
		for (int i = 0; i < str_num.length(); i++)
		{
			a[str_num.length() - i - 1] = str_num[i] - '0';
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Number::div_success(int num)
bool Number::div_success(longint num)
{
	num = fabs(num);
	for (int i = MAXN - 1; i >= 1; i--)
	{
		longint div_tmp = a[i] % num;
		a[i] = 0;
		a[i-1] += (div_tmp * 10);
	}
	if (a[0] % num == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		Number number;
		string str;
		cin >> str;
		number.set_value(str);
		longint num;
		cin >> num;
		if (number.div_success(num))
		{
			cout << divisible     << endl;
		}
		else
		{
			cout << not_divisible << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

