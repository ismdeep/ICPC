/* 
 * Project Name : 1147
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Oct  2 23:28:02 2013 
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

int add_to (int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return n+add_to (n-1);
	}
}

int main () 
{
	cout << add_to (100) << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

