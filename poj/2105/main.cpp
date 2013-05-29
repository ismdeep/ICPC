/*
 * Project     : 2105
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Sep 13 20:23:18 2012 
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

void decode_ip_msg(string str_ip_msg)
{
	int a, b, c, d;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	for (int i = 0; i < 8; i++)
	{
		a *= 2;
		a += (str_ip_msg[i] - '0');
	}
	for (int i = 8; i < 16; i++)
	{
		b *= 2;
		b += (str_ip_msg[i] - '0');
	}
	for (int i = 16; i < 24; i++)
	{
		c *= 2;
		c += (str_ip_msg[i] - '0');
	}
	for (int i = 24; i < 32; i++)
	{
		d *= 2;
		d += (str_ip_msg[i] - '0');
	}
	printf("%d.%d.%d.%d\n", a, b, c, d);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str_ip_msg;
		cin >> str_ip_msg;
		decode_ip_msg(str_ip_msg);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

