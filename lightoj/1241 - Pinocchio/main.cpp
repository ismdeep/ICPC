/* 
 * Project Name : 1241
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Fri Dec 21 15:47:53 2012 
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
	int nCaseCount;
	cin >> nCaseCount;
	for (int case_index = 1; case_index <= nCaseCount; case_index++)
	{
		cout << "Case " << case_index << ": ";
		int add_count = 0;
		int n;
		cin >> n;
		int n_one, n_two;
		cin >> n_one;
		n_two = n_one;
		n--;
		while (n--)
		{
			n_one = n_two;
			cin >> n_two;
			if (n_one < n_two)
			{
				add_count++;
			}
			// add_count += (n_two - n_one);
		}
		cout << add_count << endl;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

