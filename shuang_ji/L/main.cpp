/* 
 * Project Name : L
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 14:29:57 2012 
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
	int c, a, b;
	while (cin >> c >> a >> b)
	{
		bool iFlag = false;
		if (c % a == 0)
		{
			iFlag = true;
		}
		if (c % b == 0)
		{
			iFlag = true;
		}
		while (a > 0 && b > 0)
		{
			if (a > b)
			{
				if (a - b != 0 && c % (a - b) == 0)
				{
					iFlag = true;
				}
				a = a - b;
			}
			else
			{
				if (b - a != 0 && c % (b - a) == 0)
				{
					iFlag == true;
				}
				b = b - a;
			}
		}
		if (iFlag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO"  << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

