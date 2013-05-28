/* 
 * Project Name : E
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 12:50:44 2012 
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

int up[210];
int down[210];

int iGcd (int a, int b)
{
	a = fabs (a);
	b = fabs (b);
	while (b)
	{
		int iTmp;
		iTmp = a % b;
		a    = b;
		b    = iTmp;
	}
	return a;
}

int main () 
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = n; i >= 0; i--)
		{
			cin >> up[i];
		}
		for (int i = m; i >= 0; i--)
		{
			cin >> down[i];
		}
		if(n > m)
		{
			if ((up[n] > 0 && down[m] > 0) || (up[n] < 0 && down[m] < 0))
			{
				cout << "Infinity" << endl;
			}
			else
			{
				cout << "-Infinity" << endl;
			}
		}
		else if (n == m)
		{
			if (down[m] < 0)
			{
				up[n] = 0 - up[n];
				down[n] = 0 - down[n];
			}
			cout << up[n] / iGcd (up[n], down[m]) << "/" << down[m] / iGcd (up[n] , down[m]) << endl;
		}
		else
		{
			cout << "0/1" << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

