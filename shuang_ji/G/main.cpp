/* 
 * Project Name : G
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 13:40:23 2012 
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
	int n;
	while (scanf ("%d", &n) != EOF&& n)
	{
		int sum = 0;
		int count = 0;
		while (n--)
		{
			int iTmp;
			// cin >> iTmp;
			scanf ("%d", &iTmp);
			if (iTmp % 2 == 0)
			{
				count++;
			}
		}
		if (count % 2 == 1)
		{
			cout << "Alice" << endl;
		}
		else
		{
			cout << "Bob"   << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

