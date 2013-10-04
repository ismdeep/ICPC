/* 
 * Project Name : 1156
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Oct  4 23:18:59 2013 
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
	double x, y;
	int a, b;
	while (cin >> a >> b >> x >> y)
	{
		double ans = (float)(a+b)/2+(int)x%(int)y;
		printf ("%.6lf\n", ans);
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

