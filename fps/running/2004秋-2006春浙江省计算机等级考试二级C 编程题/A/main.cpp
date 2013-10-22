/*
 * Project     : A
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 14:52:09 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

int main()
{
	int a[10];
	// input data
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	int min_flag = 0;
	for (int i = 0; i < 10; i++)
	{
		if (abs(a[i]) < abs(a[min_flag]))
		{
			min_flag = i;
		}
	}
	// swap
	int tmp;
	tmp         = a[9];
	a[9]        = a[min_flag];
	a[min_flag] = tmp;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

// end 
// iCoding@CodeLab
//

