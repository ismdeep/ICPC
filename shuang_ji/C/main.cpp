/* 
 * Project Name : C
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 12:15:45 2012 
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
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < (n * 2 + 1); i++)
		{
			cout << "*";
		}
		cout << endl;
		for (int i = 0; i < (n * 2 - 1); i++)
		{
			for (int j = 0; j < (n * 2 - i - 1); j++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}
		for (int i = 0; i < (n * 2 + 1); i++)
		{
			cout << "*";
		}
		cout << endl << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

