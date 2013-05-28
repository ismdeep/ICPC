/*
 * Project     : 2853
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 21 19:22:34 2012 
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

// #define _DEBUG_

typedef unsigned long long int longint;

longint judge (longint num)
{
	longint stop = sqrt ((double)(2 * num)) + 1;
	longint count = 0;
	for (int length = 2; length <= stop; length++)
	{
		longint a;
		a = (((2 * num) / length) + 1 - length) / 2;
		if ((a + a + length - 1) * length == 2 * num && a > 0)
		{
#ifdef _DEBUG_
			cout << a << " - " << length << endl;
#endif
			count++;
		}
	}
	return count;
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		longint case_id;
		longint num;
		scanf ("%lld%lld", &case_id, &num);
		longint count;
		count = judge (num);
		printf ("%lld %lld\n", case_id, count);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

