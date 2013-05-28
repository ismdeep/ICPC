/* 
 * Project Name : 1007
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Nov 27 10:27:17 2012 
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

#define MAXN 110000

bool iMap[MAXN];

void init_iMap ()
{
	for (int i = 0; i < MAXN; i++)
	{
		iMap[i] = true;
	}
	for (int i = 2; i * i < MAXN; i++)
	{
		if (iMap[i])
		{
			for (int j = i * i; j < MAXN; j += i)
			{
				iMap[j] = false;
			}
		}
	}
	iMap[0] = false;
	iMap[1] = false;
}

int main () 
{
	init_iMap ();
	int n;
	while (cin >> n)
	{
		for (int i = 2; i <= n; i++)
		{
			if (iMap[i])
			{
				cout << i << endl;
			}
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

