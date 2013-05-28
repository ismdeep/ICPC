/* 
 * Project Name : 1002
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Nov 17 15:49:26 2012 
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
		int  n;
		cin >> n;
		int iSum;
		iSum = 0;
		while (n--)
		{
			int iTmp;
			cin >> iTmp;
			iSum += iTmp;
		}
		cout << iSum << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

