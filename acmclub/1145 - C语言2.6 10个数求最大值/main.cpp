/* 
 * Project Name : 1145
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 15:21:26 2013 
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
	int max, tmp;
	cin >> max;
	for (int i = 0; i < 9; i++)
	{
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
	}
	cout << max << endl;
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

