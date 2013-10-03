/* 
 * Project Name : 1155
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Oct  2 23:24:03 2013 
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
	int a;
	cin >> x >> a >> y;
	double ans = x+a%3*(int)(x+y)%2/4;
	printf ("%.6lf\n", ans);
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

