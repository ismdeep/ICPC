/* 
 * Project Name : 12577
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Dec 26 20:41:22 2013 
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
	string str;
	int ci = 0;
	while (cin >> str, str[0] != '*')
	{
		ci ++;
		cout << "Case " << ci << ": ";
		if ("Hajj" == str)
		{
			cout << "Hajj-e-Akbar" << endl;
		}
		else
		{
			cout << "Hajj-e-Asghar" << endl;
		}
	}
	return 0;
} 
// end 
// ismdeep
// xTarget
// 

