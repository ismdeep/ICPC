/*
 * Project     : 1002
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep  8 12:30:38 2012 
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

#define MAXN 100100

typedef unsigned long long int longint;

int n;

class Card
{
	public:
		int h;
		int w;
		// bool used;
};

bool cmp(Card a, Card b)
{
	return (a.h > b.h || (a.h == b.h && a.w > b.w));
}

Card alice[MAXN];
Card bob[MAXN];

int main()
{
	int iT;
	scanf("%d", &iT);
	while (iT--)
	{
		scanf("%d", &n);
		// cout << n << endl;
		// Card alice[MAXN];
		// Card bob[MAXN];
		// input data
		// alice
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &alice[i].h, &alice[i].w);
			// alice[i].used = false;
		}
		// bob
		for (int i = 0 ; i < n; i++)
		{
			scanf("%d%d", &bob[i].h, &bob[i].w);
			// bob[i].used = false;
		}
		// start do that reduce
		int count = 0;
		// sort alice and bob
		sort(alice, alice + n, cmp);
		sort(bob,   bob   + n, cmp);
		//
		//
		// show sorted
		/*
		for (int i = 0; i < n ; i++)
		{
			cout << alice[i].h << " " << alice[i].w << " - " << bob[i].h << " " << bob[i].w << endl;
		}
		cout << endl;
		*/
		//
		// do the reduce
		int bottom = 0;
		for (int i = 0; i < n; i++)
		{
			bool found = false;
			for (int j = n - 1; !found && j >= bottom; j--)
			{
				if (alice[i].h >= bob[j].h && alice[i].w >= bob[j].w)
				{
					count++;
					found = true;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

