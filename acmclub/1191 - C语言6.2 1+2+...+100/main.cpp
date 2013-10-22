/* 
 * Project Name : 1191
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 19:38:01 2013 
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

int get_sum (int n)
{
	if (0 == n)
	{
		return 0;
	}
	else
	{
		return n+get_sum(n-1);
	}
}

int main () 
{
	cout << get_sum (100) << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

