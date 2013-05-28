/*
 * Project     : 1022
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Aug 30 11:33:38 2012 
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

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		double r;
		cin >> r;
		double s_square;
		double s_circle;
		double pi = 2 * acos(0.0);
		s_square = (double)2 * (double)2 * r * r;
		s_circle = pi * r * r;
		printf("%.2f\n", s_square - s_circle);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

