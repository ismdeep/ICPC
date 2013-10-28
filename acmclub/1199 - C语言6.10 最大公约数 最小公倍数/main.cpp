/* 
 * Project Name : 1199
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Oct 28 12:19:18 2013 
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

typedef long long int LL;

LL gcd (LL a, LL b)
{
	LL tmp;
	while (b)
	{
		tmp = a % b;
		a   = b;
		b   = tmp;
	}
	return a;
}

LL lcm (LL a, LL b)
{
	return a / gcd (a,b) * b;
}

int main () 
{
	LL a, b;
	while (cin >> a >> b && (a != 0 && b != 0))
	{
		cout << gcd (a,b) << " " << lcm (a,b) << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

