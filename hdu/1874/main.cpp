// Project name : 1874 ( 畅通工程续 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 15:13:21 2012


#include <iostream>
using namespace std;
#define MAXN 210
int n, k;

int map[MAXN][MAXN];

void CInitMap()
{
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
		{
			map[i][j] = 0;
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		int a, b, weight;
		cin >> a >> b >> weight;
		map[a][b] = weight;
	}

}

void CWarShell()
{
	for (int k = 0; k < n; k++)
	{
	    for (int i = 0; i < n; i++)
		{
		    if (map[i][k] != 0)
			{
			    for (int j = 0; j < n; j++)
				{
					if (map[k][j] != 0)
					{
						if (map[i][j] == 0)
						{
						    map[i][j] = map[i][k] + map[k][j];
						}
						else if (map[i][j] > (map[i][k] + map[k][j]))
						{
						    map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}
		}
	}
}

int main()
{
	while (cin >> n >> k)
	{
	    CInitMap();
		CWarShell();
		int x, y;
		cin >> x >> y;
		if (map[x][y] == 0)
		{
			cout << "-1" << endl;
		}
		else
		{
		    cout << map[x][y] << endl;
		}
	}
    return 0;
}

// end 
// ism 

