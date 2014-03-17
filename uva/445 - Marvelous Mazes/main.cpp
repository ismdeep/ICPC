/* 
 * Project Name : 445
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Dec 17 22:45:50 2013 
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
	char ch;
	int count = 0;
	while (cin.get(ch))
	{
		if ('!' == ch)
		{
			cout << endl;
		}
		else if ('\n' == ch)
		{
			cout << endl;
		}
		else
		{
			if ('0' <= ch && ch <= '9')
			{
				int a = ch - '0';
				count += a;
			}
			else
			{
				while (count--)
				{
					if ('b' == ch)
					{
						cout << " ";
					}
					else
					{
						cout << ch;
					}
				}
				count = 0;
			}
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

