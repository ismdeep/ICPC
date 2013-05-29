// Project name : warshell
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 10:54:22 2012


#include <iostream>
using namespace std;

#define MAXN 510
const bool cango  = true;
const bool cantgo = false;

int n, k;

int map[MAXN][MAXN];


/***********************************************************************/
void CInitMap()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
		    map[i][j] = cantgo;
		}
	}

	for (int i = 0; i < k; i++)
	{
	    int a, b;
		cin >> a >> b;
		map[a][b] = cango;
	}
}
/***********************************************************************/
void CWarShell()
{
	for (int k = 1; k <= n; k++)
	{
	    for (int i = 1; i <= n; i++)
		{
		    if (map[i][k] == cango)
			{
			    for (int j = 1; j <= n; j++)
				{
				    if (map[k][j] == cango)
					{
					    map[i][j] = cango;
					}
				}
			}
		}
	}
}
/***********************************************************************/
void CShowMap()
{
    for (int i = 1; i <= n; i++)
	{
	    for (int j = 1; j <= n; j++)
		{
		    if (map[i][j] == cango)
			{
			    cout << "1 ";
			}
			else
			{
			    cout << "0 ";
			}
		}
		cout << endl;
	}
}
/***********************************************************************/
int main()
{
	while (cin >> n >> k)
	{
	    CInitMap();

		CWarShell();

		CShowMap();

	}
    return 0;
}

// end 
// ism 

