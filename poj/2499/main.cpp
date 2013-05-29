/*
 * Project     : 2499
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 14 12:31:14 2012 
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

typedef unsigned long long int longint;

void cal_count(int a, int b)
{
	int left_count  = 0;
	int right_count = 0;
	int mul;
	while (a != 1 && b != 1)
	{
		if (a > b)
		{
			mul = a / b;
			a = a - b * mul;
			left_count += mul;
		}
		else
		{
			mul = b / a;
			b = b - a * mul;
			right_count += mul;
		}
	}
	left_count  += (a - 1);
	right_count += (b - 1);
	printf("%d %d\n\n", left_count, right_count);
	// cout << left_count << " " << right_count << endl << endl;
}

int main()
{
	int t;
	// cin >> t;
	scanf("%d", &t);
	for (int case_count = 1; case_count <= t; case_count++)
	{
		//cout << "Scenario #" << case_count << ":" << endl;
		printf("Scenario #%d:\n", case_count);
		int a, b;
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		cal_count(a, b);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

