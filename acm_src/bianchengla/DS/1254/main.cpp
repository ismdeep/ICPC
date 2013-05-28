/*
 * Project     : 1254
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep 02 18:45:15 2012 
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

char ch_array[20000];
int top;

void init()
{
	top = -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		char ch;
		while (cin.get(ch) && ch != '.')
		{
			top++;
			ch_array[top] = ch;
		}
		cin.get(ch);
		//cin.get(ch);
		for (int i = top; i >= 0; i--)
		{
			cout << ch_array[i];
		}
		cout << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

