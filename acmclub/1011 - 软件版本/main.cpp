/* 
 * Project Name : 1011
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Fri Sep 27 16:42:03 2013 
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
		int a[3];
		int _a[3];
		for (int i = 0; i < 3; i++){ cin >> a[i];}
		for (int i = 0; i < 3; i++){ cin >> _a[i];}
		bool first = false;
		bool second = false;
		bool same = true;
		for (int i = 0; i < 3; i++)
		{
			if (a[i] > _a[i])
			{
				if (same)
				{
					first = true;
					same = false;
				}
			}
			else if (a[i] < _a[i])
			{
				if (same)
				{
					second = true;
					same = false;
				}
			}
		}
		if (first) {cout << "First" << endl;}
		if (second) {cout << "Second" << endl;}
		if (same) {cout << "Same" << endl;}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

