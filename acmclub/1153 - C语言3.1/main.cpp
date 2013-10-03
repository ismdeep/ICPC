/* 
 * Project Name : 1153
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Oct  3 22:37:21 2013 
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
	short int n;
	while (scanf ("%d", &n) != EOF)
	{
		if (n < 0)
		{
			n = 0 - n;
			printf ("-%o -%x\n",n,n);
		}
		else
		{
			printf ("%o %x\n",n,n);
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

