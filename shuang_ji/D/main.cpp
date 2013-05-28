/* 
 * Project Name : D
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Sat Dec  1 12:23:39 2012 
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
	int iT;
	cin >> iT;
	while (iT--)
	{
		int n, mod_odd, mod_even;
		cin >> n >> mod_odd >> mod_even;
		for (int case_count = 1; case_count <= n; case_count++)
		{
			char str_url[110];
			scanf ("%s", str_url);
			int value = 0;
			int sum = 0;
			int sum_odd  = 0;
			int sum_even = 0;
			for (int i = 0; i < strlen(str_url); i++)
			{
				if (1 == i % 2)
				{
					sum_even += str_url[i];
				}
				else
				{
					sum_odd  += str_url[i];
				}
				sum += str_url[i];
			}
			value = (sum_odd % mod_odd) + (sum_even % mod_even);
			cout << "(" << value << "," << sum << ")" << endl;
		}
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

