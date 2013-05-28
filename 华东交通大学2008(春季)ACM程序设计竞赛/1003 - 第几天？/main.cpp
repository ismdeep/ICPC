/* 
 * Project Name : 1003
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Nov 17 15:53:06 2012 
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

int month_count [13];

void init_month_count_data ()
{
	month_count[0 ] = 0;
	month_count[1 ] = 31;
	month_count[2 ] = 28;
	month_count[3 ] = 31;
	month_count[4 ] = 30;
	month_count[5 ] = 31;
	month_count[6 ] = 30;
	month_count[7 ] = 31;
	month_count[8 ] = 31;
	month_count[9 ] = 30;
	month_count[10] = 31;
	month_count[11] = 30;
	month_count[12] = 31;
}

bool is_leap_year (int iYear)
{
	return (0 == iYear % 400 || (0 == iYear % 4 && 0 != iYear % 100));
}

int count_index (int iYear, int iMonth, int iDay)
{
	int count_index_sum = 0;
	for (int month_index = 1; month_index < iMonth; month_index++)
	{
		count_index_sum += month_count[month_index];
	}
	count_index_sum += iDay;
	if (is_leap_year (iYear) && iMonth > 2)
	{
		count_index_sum++;
	}
	return count_index_sum;
}

int main () 
{
	init_month_count_data ();
	int iYear, iMonth, iDay;
	while (scanf ("%d/%d/%d", &iYear, &iMonth, &iDay) != EOF)
	{
#ifdef _ISM_DEBUG_
		cout << iYear  << " - " 
			 << iMonth << " - "
			 << iDay   << endl;
#endif
		cout << count_index (iYear, iMonth, iDay) << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

