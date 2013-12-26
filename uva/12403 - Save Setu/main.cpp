/* 
 * Project Name : 12403
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 25 22:21:01 2013 
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
	int tmp = 0;
	cin >> t;
	while (t--)
	{
		string cmd_shit;
		int value;
		cin >> cmd_shit;
		if ("donate" == cmd_shit)
		{
			cin >> value;
			tmp += value;
		}
		if ("report" == cmd_shit)
		{
			cout << tmp << endl;
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

