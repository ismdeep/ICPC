/* 
 * Project Name : 1009
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Nov 27 15:40:54 2012 
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

int iMap[4] = {153, 370, 371, 407};

int main () 
{
	int m, n;
	while (cin >> m >> n)
	{
		bool iFlag = false;
		for (int i = 0; i < 4; i++)
		{
			if (
					(iMap[i] >= m && iMap[i] <= n)
				||  (iMap[i] >= n && iMap[i] <= m)
			)
			{
				if (iFlag)
				{
					cout << " ";
				}
				cout << iMap[i];
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

