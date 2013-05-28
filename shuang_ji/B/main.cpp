/* 
 * Project Name : B
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 12:09:07 2012 
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

int iMap[10000];

int main () 
{
	memset (iMap, 0, sizeof (iMap));
	iMap[0] = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (i < 10)
		{
			iMap[i] = iMap[i-1] + 1;
		}
		else if (i < 100)
		{
			iMap[i] = iMap[i-1] + 2;
		}
		else if (i < 1000)
		{
			iMap[i] = iMap[i-1] + 3;
		}
		else if (i < 10000)
		{
			iMap[i] = iMap[i-1] + 4;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		bool iFlag = false;
		int iCount;
		cin >> iCount;
		for (int i = 0; !iFlag && i < 10000; i++)
		{
			if (iMap[i] == iCount)
			{
				cout << i << endl;
				iFlag = true;
			}
		}
		if (!iFlag)
		{
			cout << "-1" << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

