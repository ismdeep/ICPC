/* 
 * Project Name : 1004
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Nov 17 16:06:07 2012 
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

// #define _ISM_DEBUG_ 

bool judge_num (int iNum)
{
	int a, b, c;
	int iTmp;
	iTmp = iNum;
	a = iTmp % 10;
	iTmp /= 10;
	b = iTmp % 10;
	iTmp /= 10;
	c = iTmp % 10;
	iTmp /= 10;
#ifdef _ISM_DEBUG_
	cout << " -- " << a << " " << b << " " << c << " : " << iNum << endl;
#endif
	return (a*a*a + b*b*b + c*c*c == iNum);
}

int main () 
{
	int m, n;
	while (cin >> m >> n)
	{
#ifdef _ISM_DEBUG_
		cout << " -- " << m << " " << n << endl;
#endif
		bool iFlag = false;
		for (int iNum = m; iNum <= n; iNum++)
		{
			if (judge_num (iNum))
			{
				if (iFlag)
				{
					cout << " ";
				}
				cout << iNum;
				iFlag = true;
			}
		}
		if (!iFlag)
		{
			cout << "no";
		}
		cout << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

