/* 
 * Project Name : 1184
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 19:00:50 2013 
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
	int x;
	int y;
	cin >> x;
	if (x < 1)
	{
		y = x;
	}
	else if (x >= 10)
	{
		y = 3 * x - 11;
	}
	else
	{
		y = 2 * x - 1;
	}
	cout << y << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

