/* 
 * Project Name : 1143
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:18:42 2013 
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
		if (i % 2 == 1)
		{
			// + 
			sum += ((double)1/(double)i);
		}
		else
		{
			// - 
			sum -= ((double)1/(double)i);
		}
	}
	printf ("%.8lf\n", sum);
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

