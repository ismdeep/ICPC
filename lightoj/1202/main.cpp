/*
 * Project     : 1202
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Aug 25 17:37:40 2012 
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
	scanf("%d", &t);
	for (int case_count = 1; case_count <= t; case_count++)
	{
		printf("Case %d: ", case_count);
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if ((int)fabs(a-c) == (int)fabs(b-d))
		{
			printf("1\n");
		}
		else if (((int)fabs(a-c) % 2) == ((int)fabs(b-d) % 2))
		{
			printf("2\n");
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

