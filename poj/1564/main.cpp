/*
 * Project     : 1564
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 20:44:14 2012 
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

#define MAXN 20

class StackMsg
{
	public:
		int a[12];
		int top;
};

StackMsg msg[20000];
int msg_top;

int sum;
int n;
int data[MAXN];

int stack[MAXN];
int top;
int sum_stack;

void add_stack_msg ()
{
	msg_top++;
	msg[msg_top].top = top;
	for (int i = 0; i <= top; i++)
	{
		msg[msg_top].a[i] = stack[i];
	}
}

bool judge_exsit()
{
	int yes = false;
	for (int i = 0; !yes && i <= msg_top; i++)
	{
		int yes_tmp = true;
		if (msg[i].top != top)
		{
			yes_tmp = false;
		}
		else
		{
			for (int j = 0; j <= top; j++)
			{
				if (msg[i].a[j] != stack[j])
				{
					yes_tmp = false;
				}
			}
		}
		if (yes_tmp)
		{
			yes = true;
		}
	}
	return yes;
}

void input_data ()
{
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &data[i]);
	}
}

void show_stack ()
{
	for (int i = 0; i < top; i++)
	{
		cout << stack[i] << "+";
	}
	cout << stack[top] << endl;
}

void dfs (int index)
{
	if (index >= n || sum_stack + data[index] > sum)
	{
		return;
	}
	if (sum_stack + data[index] == sum)
	{
		top++;
		stack[top] = data[index];
		if (!judge_exsit())
		{
			show_stack();
			add_stack_msg();
		}
		top--;
	}
	else
	{
		top++;
		stack[top] = data[index];
		sum_stack += stack[top];
		for (int i = index + 1; i < n; i++)
		{
			dfs (i);
		}
		sum_stack -= stack[top];
		top--;
	}
}

void search (int index)
{
	top = -1;
	sum_stack = 0;
	dfs (index);
}

int main()
{
	while (scanf ("%d%d", &sum, &n) != EOF && sum + n)
	{
		cout << "Sums of " << sum << ":" << endl;
		msg_top = -1;
		input_data();
		for (int i = 0; i < n; i++)
		{
			search (i);
		}
		if (msg_top == -1)
		{
			cout << "NONE" << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

