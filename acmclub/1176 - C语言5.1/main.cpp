/* 
 * Project Name : 1176
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 18:49:10 2013 
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
	double a, b;
	while (cin >> a >> b)
	{
		if (a < b)
		{
			printf ("%.2f %.2f\n",a,b);
		}
		else
		{
			printf ("%.2f %.2f\n",b,a);
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

