/*
 * Project     : 1072
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Aug 30 14:44:11 2012 
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

double pi;
double iMap[110];

void init_pi_iMap()
{
	pi = (double)2 * acos((double)0.0);
	for (int i = 2; i < 110; i++)
	{
		iMap[i] = sin(pi / (double)i);
	}
}

double cal_result(double R, int n)
{
	return R * iMap[n] / ((double)1 + iMap[n]);
}

int main()
{
	init_pi_iMap();
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		double R;
		int n;
		cin >> R >> n;
		double ans;
		ans = cal_result(R, n);
		if (fabs(ans - (int)ans) <= 1E-07)
		{
			printf("%d\n",(int)ans);
		}
		else
		{
			printf("%.10lf\n", ans);
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

