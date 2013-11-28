/*
 * Project     : 1136
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Thu Aug 30 15:18:49 2012 
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

longint cal_result(longint start, longint end)
{
	longint count = 0;
	//
	//
	if (start % 3 == 0)
	{
		start -= 2;
		count--;
	}
	else if (start % 3 == 2)
	{
		start -= 1;
	}
	//
	//
	if (end % 3 == 1)
	{
		end += 2;
		count -= 2;
	}
	else if (end % 3 == 2)
	{
		end += 2;
		count--;
	}
	//
	//
	// cout << start << " " << end << endl;
	return count + (end - start + 1) / 3 * 2;
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		longint start, end;
		cin >> start >> end;
		cout << cal_result (start, end) << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

