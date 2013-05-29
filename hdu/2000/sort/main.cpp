/*
 * Project     : sort
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 21:12:17 2012 
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
using namespace std;

typedef long long int longint;

bool cmp(int x, int y)
{
	return (x > y) ? true : false;
}

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 10, cmp);
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

