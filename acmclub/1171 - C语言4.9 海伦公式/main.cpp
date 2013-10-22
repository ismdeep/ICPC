/* 
 * Project Name : 1171
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 18:33:21 2013 
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
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a+b+c)/2;
	double area = sqrt(p*(p-a)*(p-b)*(p-c));
	printf ("%.2lf\n", area);
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

