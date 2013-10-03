/* 
 * Project Name : 1150
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Oct  3 22:25:05 2013 
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

int gcd (int a, int b)
{
	int tmp;
	while (b)
	{
		tmp = a % b;
		a   = b;
		b   = tmp;
	}
	return a;
}

int main () 
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << gcd (a,b) << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

