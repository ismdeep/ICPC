/* 
 * Project Name : 1177
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 18:25:41 2013 
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
	double a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort (a,a+3);
	cout << a[0] << " "
		 << a[1] << " "
		 << a[2] << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

