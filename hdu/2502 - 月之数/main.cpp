/* 
 * Project Name : 2502
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Thu Nov 28 22:36:12 2013 
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

int pow_2 (int n)
{
	int re = 1;
	while (n--)
	{
		re *= 2;
	}
	return re;
}

int cal_dig (int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += (n%2);
		n /= 2;
	}
	return cnt;
}


int main () 
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int left;
		int right;
		left = pow_2 (n-1);
		right = pow_2 (n);
		int cnt = 0;
		for (int value = left; value < right; value++)
		{
			cnt += cal_dig (value);
		}
		cout << cnt << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

