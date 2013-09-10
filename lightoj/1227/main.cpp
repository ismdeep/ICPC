/*
 * Project     : 1227
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Sep 17 20:10:46 2012 
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
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

#define MAXN 110
int data[MAXN];
int n, p, q;

bool cmp(int a, int b)
{
	return (a < b);
}

int main()
{
	int iT;
	scanf("%d", &iT);
	for (int case_count = 1; case_count <= iT; case_count++)
	{
		cout << "Case " << case_count << ": ";
		cin >> n >> p >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}
		sort(data, data + n, cmp);
		int current_gm = 0;
		int count      = 0;
		for (int index = 0; index < n; index++)
		{
			if (data[index] + current_gm <= q)
			{
				current_gm += data[index];
				count++;
			}
		}
		if (count > p)
		{
			count = p;
		}
		cout << count << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

