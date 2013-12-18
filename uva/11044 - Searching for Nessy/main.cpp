/* 
 * Project Name : 11044
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 16:35:02 2013 
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
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		a--; b--;
		if (a % 3)
		{
			a /= 3;
			a++;
		}
		else
		{
			a /= 3;
		}
		if (b % 3)
		{
			b /= 3;
			b++;
		}
		else
		{
			b /= 3;
		}
		cout << a * b << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

