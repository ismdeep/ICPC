/* 
 * Project Name : 2501
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Nov 29 09:20:47 2013 
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

typedef long long int LL;

LL a[33];

void make_shit_map ()
{
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i < 33; i++)
	{
		a[i] = a[i-1]+2*a[i-2];
#ifdef _ISM_DEBUG_
		cout << a[i] << endl;
#endif
	}
}

int main () 
{
	make_shit_map ();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

