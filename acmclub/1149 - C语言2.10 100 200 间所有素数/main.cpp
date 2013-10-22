/* 
 * Project Name : 1149
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Oct  3 22:21:08 2013 
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

bool is_prime (int n)
{
	int tmp = (int)sqrt((double)n + 0.5);
	bool isok = true;
	for (int i = 2; isok && i <= tmp; i++)
	{
		if (n % i == 0)
		{
			isok = false;
		}
	}
	return isok;
}

int main () 
{ 
	for (int i = 100; i <= 200; i++)
	{
		if (is_prime(i))
		{
			cout << i << endl;
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

