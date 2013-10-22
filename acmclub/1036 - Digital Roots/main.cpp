/* 
 * Project Name : 1036
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Nov 27 15:35:57 2012 
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
	while (cin >> str && "0" != str)
	{
		int iSum = 0;
		for (int i = 0; i < str.length(); i++)
		{
			iSum += (str[i] - '0');
		}
		while (iSum >= 10)
		{
			int iTmp = iSum;
			iSum = 0;
			while (iTmp > 0)
			{
				iSum += (iTmp % 10);
				iTmp /= 10;
			}
		}
		cout << iSum << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

