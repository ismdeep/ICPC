/*
 * Project     : 2845
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 19:38:38 2012 
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

typedef unsigned long long int longint;

class Number
{
	public:
		int data[MAXN];
		void set_value  (string str_num);
		void plus_value (string str_num);
		void manage ();
		void show_value ();
};

void Number::set_value (string str_num)
{
	int top = str_num.length() - 1;
	// init for data[] array
	for (int i = 0; i < MAXN; i++)
	{
		data[i] = 0;
	}
	// set value by str_num
	for (int i = 0; i <= top; i++)
	{
		data[top-i] = str_num[i] - '0';
	}
}

void Number::plus_value (string str_num)
{
	int top = str_num.length() - 1;
	for (int i = 0; i <= top; i++)
	{
		data[top-i] += str_num[i] - '0';
	}
}

void Number::manage ()
{
	for (int i = 0; i <= MAXN - 2; i++)
	{
		data[i+1] += data[i] / 2;
		data[i]   %= 2;
	}
}

void Number::show_value ()
{
	int top = MAXN - 1;
	while (data[top] == 0 && top >= 0)
	{
		top--;
	}
	if (top < 0)
	{
		top = 0;
	}
	for (int i = top; i >= 0; i--)
	{
		printf ("%d", data[i]);
	}
	printf ("\n");
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << case_count << " ";
		string str_num;
		cin >> str_num;
		Number number;
		number.set_value(str_num);
		cin >> str_num;
		number.plus_value(str_num);
		number.manage();
		number.show_value();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

