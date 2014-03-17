/* 
 * Project Name : 12279
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 25 20:24:29 2013 
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
	int case_index = 0;
	while (cin >> n, n)
	{
		case_index++;
		cout << "Case " << case_index << ": ";
		int a, b;
		a = 0;
		b = 0;
		int tmp;
		while (n--)
		{
			cin >> tmp;
			if (0 == tmp)
			{
				b++;
			}
			else
			{
				a++;
			}
		}
		cout << a - b << endl;
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

