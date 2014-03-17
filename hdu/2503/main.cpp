/* 
 * Project Name : 2503
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Nov 28 22:25:09 2013 
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
		a = b;
		b = tmp;
	}
	return a;
}

int main () 
{
	int t;
	cin >> t;
	while (t--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int up,down;
		up = a*d+c*b;
		down = b*d;
		int eee = gcd (up,down);
		up /= eee;
		down /= eee;
		cout << up << " " << down << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

