/* 
 * Project Name : 2523
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Nov 29 10:52:05 2013 
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

#define VALUE_MAX 2200

bool shit[VALUE_MAX];

void init_shit ()
{
	for (int i = 0; i < VALUE_MAX; i++)
	{
		shit[i] = false;
	}
}

int main () 
{
	int t;
	cin >> t;
	while (t--)
	{
		init_shit ();
		int n,k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		// ---- make the shit
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				shit[abs(a[i]-a[j])] = true;
			}
			for (int j = i + 1; j < n; j++)
			{
				shit[abs(a[i]-a[j])] = true;
			}
		}
		// ---- get the answer
		int max_value = 0;
		if (shit[0])k--;
		while (k--)
		{
			max_value++;
			while (max_value < VALUE_MAX && !shit[max_value])max_value++;
		}
		cout << max_value <<  endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

