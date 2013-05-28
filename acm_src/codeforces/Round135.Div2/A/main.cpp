/*
 * Project     : A
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 23:47:57 2012 
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

typedef long long int longint;

string guten_nothing = "-1";

int n;
string s;
int s_length;

char result[10000];
int top;

const char BLOCK = 32;

bool is_empty()
{
	bool yes = true;
	for (int i = 0; yes && i < s_length; i++)
	{
		if (s[i] != BLOCK)
		{
			yes = false;
		}
	}
	return yes;
}

void init()
{
	top = -1;
	s_length = s.length();
}

bool make_k_string()
{
	/* 心情不爽，，遇到坑爹就结束 */
	bool can_go_on = true;
	while (can_go_on && !is_empty())
	{
		char ch;
		int  count = 0;
		int index = 0;
		while (s[index] == BLOCK)
		{
			index++;
		}
		ch = s[index];
		for (int i = 0; i < s_length; i++)
		{
			if (s[i] == ch)
			{
				count++;
				s[i] = BLOCK;
			}
		}
		if (count % n != 0)
		{
			can_go_on = false;
		}
		else
		{
			count = count / n;
			for (int i = 0; i < count; i++)
			{
				top++;
				result[top] = ch;
			}
		}
	}
	if (can_go_on)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	while (cin >> n >> s)
	{
		init();
		//
		//
		if (s_length % n != 0)
		{
			cout << guten_nothing << endl;
		}
		else
		{
			if (make_k_string() == false)
			{
				cout << guten_nothing << endl;
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j <= top; j++)
					{
						cout << result[j];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

