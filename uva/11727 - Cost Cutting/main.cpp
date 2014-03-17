/* 
 * Project Name : 11727
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 14:27:56 2013 
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
	int n;
	cin >> n;
	for (int t = 1; t <= n; t++)
	{
		cout << "Case " << t << ": ";
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort (a,a+3);
		cout << a[1] << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

