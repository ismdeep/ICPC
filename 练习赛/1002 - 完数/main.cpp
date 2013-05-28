/* 
 * Project Name : 1002
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sun Nov 18 22:38:21 2012 
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

int p[8] = {6, 28, 496, 8128, 33550336};
int main () 
{ 
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
		{
			int tmp;
			tmp = a;
			a   = b;
			b   = tmp;
		}
		int count = 0;
		for (int i = 0; i <= 3; i++)
		{
			if (a <= p[i] && p[i] <= b)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

