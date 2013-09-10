/*
 * Project     : 1116
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Aug 26 17:55:10 2012 
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
		longint w;
		cin >> w;
		longint m = 1;
		if (w % 2 == 1)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			while (w % 2 == 0)
			{
				m *= 2;
				w /= 2;
			}
			cout << w << " " << m << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

