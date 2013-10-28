/* 
 * Project Name : 1192:C语言6.3
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Oct 11 09:19:46 2013 
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
	int n = 1;
	int sum = 0;
	do
	{
		sum += n++;
	} while (n <= 100);
	cout << sum << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

