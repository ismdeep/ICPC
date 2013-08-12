/*
 * Project     : Bv2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Aug 28 01:28:36 2012 
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

typedef unsigned long long int longint;

class Number
{
public:
	int a[21];
	int top;
	//
	//
	void    init();
	void    set_value(longint num);
	longint get_value();
	void    show_a_array();
};

/////////////////////////////////////////////////////////////////////
void Number::init()
{
	top = -1;
}

void Number::set_value(longint num)
{
	for (int i = 0; i < 21; i++)
	{
		a[i] = 0;
	}
	while (num)
	{
		top++;
		a[top] = num % 10;
		num /= 10;
	}
	if (top == -1)
	{
		top = 0;
	}
}

longint Number::get_value()
{
	longint tmp = 0;
	for (int i = 20; i >= 0; i--)
	{
		tmp *= 10;
		tmp += a[i];
	}
	return tmp;
}

void Number::show_a_array()
{
	for (int i = 20; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
/////////////////////////////////////////////////////////////////////
int main()
{
	longint p, d;
	while (cin >> p >> d)
	{
		Number number;
		number.init();
		number.set_value(p);
		for (int i = 0; i < 21; i++)
		{
			if (number.a[i] != 9)
			{
			}
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

