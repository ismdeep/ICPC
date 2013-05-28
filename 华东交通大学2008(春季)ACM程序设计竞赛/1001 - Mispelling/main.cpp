/* 
 * Project Name : 1001
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Nov 17 11:41:37 2012 
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
	for (int case_count = 1; case_count <= t; case_count++)
	{
		cout << case_count << " ";
		int iIndex;
		string iStr;
		cin >> iIndex >> iStr;
		for (int i = 0; i < iStr.length(); i++)
		{
			if (i + 1 != iIndex)
			{
				cout << iStr[i];
			}
		}
		cout << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

