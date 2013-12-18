/* 
 * Project Name : 11547
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 22:58:53 2013 
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int value = (n*567/9+7492)*235/47-498;
		if (value < 0)
		{
			value = 0 - value;
		}
			value /= 10;
			cout << value % 10 << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

