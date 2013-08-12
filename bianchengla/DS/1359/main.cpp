/*
 * Project     : 1359
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 19:30:24 2012 
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

class Stack
{
public:
	// data
	char data[10000];
	int top;
	// procedure
	void init();
	char get_top();
	void pop();
	void push(char ch);
	void clear_top();
	bool is_empty();
};

/////////////////////////////////////////////////////////////////////
void Stack::init()
{
	top = 0;
	data[0] = '0';
}

/////////////////////////////////////////////////////////////////////
char Stack::get_top()
{
	return data[top];
}

/////////////////////////////////////////////////////////////////////
void Stack::pop()
{
	top--;
}

/////////////////////////////////////////////////////////////////////
void Stack::push(char ch)
{
	top++;
	data[top] = ch;
}

/////////////////////////////////////////////////////////////////////
void Stack::clear_top()
{
	// doing nothing
}

/////////////////////////////////////////////////////////////////////
bool Stack::is_empty()
{
	if (top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/////////////////////////////////////////////////////////////////////
int main()
{
	int iT;
	scanf("%d", &iT);
	while (iT--)
	{
		string s;
		cin >> s;
		Stack stack;
		stack.init();
		for (int i = 0; i < s.length(); i++)
		{
			char ch_tmp = stack.get_top();
			if (
					(ch_tmp == '{' && s[i] == '}')
				  ||(ch_tmp == '[' && s[i] == ']')
				  ||(ch_tmp == '(' && s[i] == ')')
					)
			{
				stack.pop();
			}
			else
			{
				stack.push(s[i]);
			}
		}
		//
		//
		// judge 
		if (stack.is_empty())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No"  << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

