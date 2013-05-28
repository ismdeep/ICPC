/* 
 * Project Name : A
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 12:05:17 2012 
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

typedef long long int longint;

int main () 
{
	longint n;
	while (cin >> n)
	{
		longint sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += (i * i);
		}
		cout << sum << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

