// Project name : 1285
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 14:32:46 2012

#include <iostream>
using namespace std;

#define MAXN 510
const bool noway  = false;
const bool hasway = true;

int n, k;

bool map[MAXN][MAXN];

void CInitMap()
{
    for (int i = 0; i <= n; i++)
	{
	    for (int j = 0; j <= n; j++)
		{
		    map[i][j] = noway;
		}
	}

	for (int i = 0; i < k; i++)
	{
	    int a, b;
		cin >> a >> b;
		map[a][b] = hasway;
	}
}

int main()
{
	int t;
	while (cin >> n >> k)
	{
	    CInitMap();

	}
}

// end 
// ism 

