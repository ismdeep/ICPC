/* 
 * Project Name : 12372
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Dec 26 20:32:24 2013 
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

int main () 
{
	int t;
	cin >> t;
	int ci = 0;
	while (t--)
	{
		ci ++;
		cout << "Case " << ci << ": ";
		int a, b, c;
		cin >> a >> b >> c;
		a = max (a,b);
		a = max (a,c);
		if (a > 20)
		{
			cout << "bad" << endl;
		}
		else
		{
			cout << "good" << endl;
		}
	}
	return 0;
} 
// end 
// ismdeep
// xTarget
// 

