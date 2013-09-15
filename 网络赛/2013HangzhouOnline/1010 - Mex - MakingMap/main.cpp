#include <cmath>
#include <time.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::fstream;

namespace ism
{
	using std::ifstream;
	using std::ios;
	ifstream cin ("in.dat", ios::in);
};

using ism::cin;

#define MAXN 100

int arr[MAXN];
int _map_[MAXN][MAXN];


int n;

int sum;

void init_map ()
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			_map_[i][j] = -1;
		}
	}
	sum = 0;
}

void set_l_r (int l, int r)
{
	bool used[MAXN];
	for (int i = 0; i < MAXN; i++)
	{
		used[i] = false;
	}
	for (int i = l; i <= r; i++)
	{
		used[arr[i]] = true;
	}
	int min_no_used = -1;
	for (int i = 0; -1 == min_no_used && i < MAXN; i++)
	{
		if (!used[i])
		{
			min_no_used = i;
		}
	}
	_map_[l][r] = min_no_used;
	sum += min_no_used;
}

int main ()
{

	int n;
	int seed = 1;
	while (cin >> n)
	{
		init_map ();
		srand (seed * n);

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				set_l_r (i, j);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%4d ", _map_[i][j]);
			}
			printf("\n");
		}
		printf("sum=%d\n", sum);
	}
	return 0;
}