/*
 * Project     : C
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 21:31:22 2012 
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

#define MAXN 11000
#define MOD 17

int data[MAXN];

void init_data_array()
{
	memset(data, 0, sizeof(data));
}

void show_data()
{
	int top = MAXN - 1;
	while (data[top] == 0)
	{
		top--;
	}
	for (int i = top; i >= 0; i--)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void decode_msg_to_data(string msg)
{
	int top = msg.length() - 1;
	for (int i = 0; i <= top; i++)
	{
		data[top-i] = (msg[i] - '0');
	}
	// show_data();
}

bool judge()
{
	int index = MAXN - 1;
	while (index)
	{
		data[index-1] += (10 * (data[index] % MOD));
		data[index] = 0;
		index--;
	}
	if (data[0] % MOD == 0)
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
	string msg;
	while (cin >> msg && msg != "0")
	{
		init_data_array();
		decode_msg_to_data(msg);
		if (judge())
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

