/* 
 * Project Name : 365A
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Nov 20 10:05:30 2013 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

bool judge (int value, int m)
{
	bool digital[10];
	for (int i = 0; i < 10; i++)
	{
		digital[i] = false;
	}
	if (value == 0)
	{
		digital[0] = true;
	}
	while (value)
	{
		digital[value%10] = true;
		value /= 10;
	}
	// ---- value;
	bool is_ok = true;
	for (int i = 0; i <= m; i++)
	{
		is_ok = digital[i] == true ? is_ok : false;
	}
	return is_ok;
}

int main () 
{
	int n,m;
	while (cin >> n >> m)
	{
		int __count = 0;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			__count += (judge(tmp,m))?1:0;
		}
		cout << __count << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

