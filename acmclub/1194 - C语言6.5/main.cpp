/* 
 * Project Name : 1194
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Oct 11 09:34:47 2013 
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
	double pi = 0.0;
	int n = 1;
	bool flag = true;
	while ((double)1/(double)n >= 0.000001)
	{
		if (flag)
		{
			pi += (double)1/(double)n;
			flag = false;
		}
		else
		{
			pi -= (double)1/(double)n;
			flag = true;
		}
		n += 2;
	}
	printf ("%.6lf\n", pi*4);
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

