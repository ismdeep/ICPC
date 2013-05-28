/*
 * Project     : 2000
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Sep 13 19:59:02 2012 
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

#define MAXN 11000

typedef unsigned long long int longint;

longint make_map(int num)
{
	longint ans = 0;
	int index = 1;
	int count = 1;
	while (index <= num)
	{
		for (int i = 0; i < count && index <= num; i++)
		{
			index++;
			ans += count;
		}
		count++;
	}
	return ans;
}


int main()
{
	int n;
	while (cin >> n && n)
	{
		int sum = make_map(n);
		cout << n << " " << sum << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

