/*
 * Project     : 1001
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep  8 12:10:33 2012 
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

#define MAXN 55000

#define QUERY 2
#define CHANGE 1

typedef long long int longint;

int data[MAXN];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &data[i]);
		}
	//
	//
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int instruc;
		scanf("%d", &instruc);
		if (instruc == QUERY)
		{
			int id;
			scanf("%d", &id);
			printf("%d\n", data[id]);
		}
		if (instruc == CHANGE)
		{
			int a;
			int b;
			int k;
			int c;
			scanf("%d%d%d%d", &a, &b, &k, &c);
			// do a, b, k, c
			for (int i = a; i <= b; i += k)
			{
				data[i] += c;
			}
		}
	}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

