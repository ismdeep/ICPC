/* 
 * Project Name : 1186
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Tue Oct  8 19:26:08 2013 
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


const int CON   = 0;
const int RIGHT = 1;
const int LEFT  = 2;


int counter (int value, int op)
{
	if (value < 10)
	{
		int re_value = 1;
		if (RIGHT == op || LEFT == op)
		{
			cout << value << " ";
		}
		return re_value;
	}
	else
	{
		if (RIGHT == op)
		{
			cout << value % 10 << " ";
		}
		int re_value = 1 + counter (value/10, op);
		if (LEFT == op)
		{
			cout << value % 10 << " ";
		}
		return re_value;
	}
}

int main () 
{
	int n;
	while (cin >> n)
	{
		cout << counter (n,0) << endl;
		counter (n,2);cout << endl;
		counter (n,1);cout << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

