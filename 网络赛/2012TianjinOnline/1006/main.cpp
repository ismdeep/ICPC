/*
 * Project     : 1006
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Sep  9 14:41:06 2012 
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

#define MAXN 1000

typedef long long int longint;

int n;
int data[MAXN];

bool cmp(int a, int b)
{
	return (a < b);
}

int main()
{
	int t;
	cin >> t;
	for (int case_count = 1; case_count <= t; case_count++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}
		sort(data, data + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += (data[i] * (n-i-1));
		}
		cout << "Case #" << case_count << ": ";
		cout << ans << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

