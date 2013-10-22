/* 
 * Project Name : 1183
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 18:53:45 2013 
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
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a < b){a=b;}
		if (a < c){a=c;}
		cout << a << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

