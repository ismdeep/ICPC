/*
 * Project     : 1069
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 14:07:55 2012 
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
		int a, b;
		cin >> a >> b;
		int ans;
		if (a == b)
		{
			ans = 19 + a * 4;
		}
		else
		{
			ans = 4 * fabs(a - b) + 19 + a * 4;
		}
		cout << ans << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

