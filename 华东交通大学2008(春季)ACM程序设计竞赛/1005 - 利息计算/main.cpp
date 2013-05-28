/* 
 * Project Name : 1005
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Nov 17 22:55:53 2012 
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
		double money, day, huo_qi, ding_qi_1, ding_qi_2;
		cin >> money >> day >> huo_qi >> ding_qi_1 >> ding_qi_2;
		double iSum;
		iSum = money * (1.0 + (huo_qi * day / 36500)) * (1 + (ding_qi_2 / 100.00));
		double isum1;
		isum1 = money * (1 + (ding_qi_1 / 100.00) * (day + 365) / 365);
		printf ("%.1lf\n%.1lf\n", iSum, isum1);
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

