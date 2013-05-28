/* 
 * Project Name : 1004
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Mon Dec 17 10:03:36 2012 
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
		int sum = 0;
		int tmp;
		while (n--)
		{
			cin >> tmp;
			sum += tmp;
		}
		cout << sum << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

