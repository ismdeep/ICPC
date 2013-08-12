/*
 * Project     : 1053
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 13:50:11 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int case_count = 1; case_count <= t; case_count++)
	{
		cout << "Case " << case_count << ": ";
		int a, b, c;
		cin >> a >> b >> c;
		int tmp;
		if (a > b){tmp = a; a = b; b = tmp;}
		if (a > c){tmp = a; a = c; c = tmp;}
		if (b > c){tmp = b; b = c; c = tmp;}
		if (a * a + b * b == c * c)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no"  << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

