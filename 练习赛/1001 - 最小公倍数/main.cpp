/* 
 * Project Name : 1001
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sun Nov 18 22:33:32 2012 
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

// #define _ISM_DEBUG_ 

typedef long long int longint;

longint iGcd (longint a, longint b)
{
	longint tmp;
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
#ifdef _ISM_DEBUG_
	cout << iGcd (4, 6) << " " << iGcd (6, 4) << endl;
#endif
	longint a, b;
	while (cin >> a >> b)
	{
		longint lcm = a / iGcd (a, b);
		lcm *= b;
		cout << lcm << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

