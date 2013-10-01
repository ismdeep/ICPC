/* 
 * Project Name : 1137
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct  1 13:45:00 2013 
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
	int a, b;
	while (scanf ("%d,%d", &a, &b) != EOF)
	{
		cout << "max=";
		if (a > b)
		{
			cout << a << endl;
		}
		else
		{
			cout << b << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

