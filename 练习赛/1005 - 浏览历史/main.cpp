/* 
 * Project Name : 1005
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sun Nov 18 22:26:25 2012 
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

int main () 
{ 
	int n;
	int case_count = 0;
	while (cin >> n)
	{
		case_count++;
		cout << "Case " << case_count << ": ";
		int iMaxSum = 0;
		for (int i = 0; i < n; i++)
		{
			int iSum = 0;
			string iStr;
			cin >> iStr;
			for (int j = 0; j < iStr.length(); j++)
			{
#ifdef _ISM_DEBUG_
				cout << iStr[j] << " " << (int)iStr[j] << endl;
#endif
				iSum += iStr[j];
			}
			if (iSum > iMaxSum)
			{
				iMaxSum = iSum;
			}
		}
		cout << iMaxSum << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

