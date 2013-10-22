/* 
 * Project Name : 1203
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Oct  3 23:00:12 2013 
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
	double sum = 0.0;
	for (int i = 1; i <= 100; i++)
	{
		sum += (double)i;
	}
	for (int i = 1; i <= 50; i++)
	{
		sum += (double)(i*i);
	}
	for (int i = 1; i <= 10; i++)
	{
		sum += (double)((double)1/i);
	}
	printf ("%.4lf\n", sum);
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

