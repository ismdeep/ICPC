/*
 * Project     : 1216
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Aug 31 10:27:00 2012 
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

int main()
{
	double pi = (double)2 * acos(0.0);
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		double r1, r2, h, p;
		cin >> r1 >> r2 >> h >> p;
		double r3;
		r3 = p / h * (r1 - r2) + r2;
		double volume = pi * p * (r3 * r3 + r3 * r2 + r2 * r2) / (double)3;
		printf("%.9lf\n", volume);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

