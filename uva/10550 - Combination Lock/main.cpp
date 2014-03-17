/* 
 * Project Name : 10550
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 15:57:11 2013 
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

//#define _ISM_DEBUG_ 

int counter_clockwise (int a, int b)
{
	if (b > a)
	{
		return b - a;
	}
	else
	{
		return 40+b-a;
	}
}

int clockwise (int a, int b)
{
	a = (40 - a) % 40;
	b = (40 - b) % 40;
	return counter_clockwise (a,b);
}


int main () 
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d, a+b+c+d)
	{
#ifdef _ISM_DEBUG_
		printf ("%d %d %d %d.\n", a, b, c, d);
#endif
		int cnt = 0;
		// -- 1st step
		cnt += 80;
		cnt += clockwise (a,b);
		// -- 2nd step
		cnt += 40;
		cnt += counter_clockwise (b,c);
		// -- 3st step
		cnt += clockwise (c,d);
		// -- 
		cnt *= 9;
		cout << cnt << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

