/*
 * Project     : 1294
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 18:05:01 2012 
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
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		longint n, m;
		cin >> n >> m;
		longint ans;
		ans = n / (2 * m);
		ans = m * m * ans;
		cout << ans << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

