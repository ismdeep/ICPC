// Project name : A
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 12:52:14 2012
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int father[110];
bool flags[110];

class country
{
public:
	int first, second, value;
};

country a[5100];


bool cmp(country x, country y)
{
	return x.value < y.value;
}

void makeset(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
}

int findset(int x)
{
	if (father[x] != x)
	{
		father[x] = findset(father[x]);
	}
	return father[x];
}

int Union(int a, int b)
{
	int x = findset(a);
	int y = findset(b);
	if (x == y)
	{
		return 1;
	}
	else
	{
		father[x] = y;
		return 0;
	}
}


int main()
{
	int n, m;
	while (cin >> n >> m && n)
	{
		int sum = 0;
		makeset(m);
		memset(flags, false, sizeof(flags));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].first >> a[i].second >> a[i].value;
		}
		sort(a + 1, a + n + 1, cmp);

		for (int i = 1; i <= n; i++)
		{
			if (Union(a[i].first, a[i].second) == 0)
			{
				sum += a[i].value;
			}
		}

		for (int i = 1; i <= m; i++)
		{
			flags[findset(i)] = true;
		}

		int k = 0;
		for (int i = 1; i <= m; i++)
		{
			if (flags[i] == true)
			{
				k++;
			}
		}

		if (k != 1)
		{
			printf("?\n");
		}
		else
		{
			printf("%d\n", sum);
		}

	}


	return 0;
}
// end 
// ism 

