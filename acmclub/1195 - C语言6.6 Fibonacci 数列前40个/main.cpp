/* 
 * Project Name : 1195
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Oct 28 12:31:05 2013 
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

typedef long long int LL;

LL fib[40];

void init ()
{
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 40; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int main () 
{
	init();
	for (int i = 0; i < 40; i++)
	{
		cout << fib[i] << " ";
	}
	cout << endl;
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

