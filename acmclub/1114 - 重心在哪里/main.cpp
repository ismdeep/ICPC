/* 
 * Project Name : 1114
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 13:37:19 2013 
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
	while (scanf ("%d", &t) , t)
	{
		while (t--)
		{
			double x[4];
			double y[4];
			x[3] = 0.0;
			y[3] = 0.0;
			for (int i = 0; i < 3; i++)
			{
				scanf ("%lf%lf", &x[i], &y[i]);
				x[3] += x[i];
				y[3] += y[i];
			}
			printf ("%.1f %.1f\n", x[3]/(double)3, y[3]/(double)3);
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

