/* 
 * Project Name : 1161
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Sat Oct  5 09:01:34 2013 
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
	int a, n;
	while (cin >> a >> n)
	{
		a%=(n%=2);
		cout << a << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

