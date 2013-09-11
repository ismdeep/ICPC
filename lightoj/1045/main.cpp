/*
 * Project     : 1045
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Aug 27 21:55:26 2012 
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
#define MAXN 1001000
double a[MAXN];

void make_a_array()
{
	a[0] = 0.0;
	a[1] = (double)log((double)1);
	for (int i = 2; i < MAXN; i++)
	{
		a[i] = a[i-1] + (double)log((double)i);
	}
}

int main()
{
	make_a_array();
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		int n, base;
		cin >> n >> base;
		double log_base;
		log_base = (double)log((double)base);
		double ans;
		ans = a[n] / log_base;
		ans += 1.0;
		cout << (int)ans << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

