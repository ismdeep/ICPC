/* 
 * Project Name : 1142
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 14:13:33 2013 
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
		if (
			   (n % 4 == 0 && n % 100 != 0)
			|| (n % 4 == 0 && n % 400 == 0)
		)
		{
			cout << "leap year" << endl;
		}
		else
		{
			cout <<"not leap year" << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

