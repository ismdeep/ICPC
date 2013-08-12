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

#define ALICE true
#define BOB   false

typedef unsigned long long int longint;

class Card
{
	public:
		longint h;
		longint w;
		bool used;
		bool usr;
};

bool cmp(Card a, Card b)
{
	return (a.h > b.h || (a.h == b.h && a.w > b.w));
}

Card card[2*MAXN];

int n;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		// input data
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &card[i].h, &card[i].w);
			card[i].used = false;
			card[i].usr = ALICE;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &card[i+n].h, &card[i+n].w);
			card[i+n].used = false;
			card[i+n].usr = BOB;
		}
		// sort that array
		sort(card, card + 2 * n, cmp);
		//
		//
		// show sorted
		/*
		for (int i = 0; i < 2 * n; i++)
		{
			cout << card[i].h << " " << card[i].w << " - ";
			if (card[i].usr == ALICE)
			{
				cout << "Alice";
			}
			else
			{
				cout << "Bob";
			}
			cout << endl;
		}
		cout << endl;
		*/
		//
		//
		// start cover
		int start = 1;
		int count = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (card[i].usr == ALICE)
			{
				bool found = false;
				for (int j = start; !found && j < 2 * n; j++)
				{
					if (card[j].usr == BOB && card[j].used == false)
					{
						if (card[i].h >= card[j].h && card[i].w >= card[j].w)
						{
							card[j].used = true;
							count++;
							found = true;
							start = j + 1;
						}
					}
				}
				
				if (found == false)
				{
					for (int j = start; !found && j < 2 * n; j++)
					{
						if (card[j].usr == BOB && card[j].used == false)
						{
							if (card[i].h >= card[j].h && card[i].w >= card[j].w)
							{
								card[j].used = true;
								count++;
								found = true;
							}
						}
					}
				}
				
			}
		}
		//
		//
		//
		//
		printf("%d\n", count);
	}
	return 0;
}

// end 
// iCoding

