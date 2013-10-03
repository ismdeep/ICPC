/* 
 * Project Name : 1152
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Wed Oct  2 23:14:14 2013 
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

bool is_leap_year (int y)
{
	return ((0 == y % 4 && 0 != y % 100) || (0 == y % 400));
}

int main () 
{ 
	for (int year = 1900; year <= 2000; year++)
	{
		if (is_leap_year(year))
		{
			cout << year << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

