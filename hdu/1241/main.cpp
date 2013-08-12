// Project name : 1241 ( Oil Deposits ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 11:42:35 2012


#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char map[100][100];
int dir[8][2] = {
	-1, -1, -1,  0, -1, 1, 0, -1,
	0 ,  1,  1,  -1, 1, 0, 1,  1
                };
int vis[100][100];

int n, m, answer;

/****************************************************/

void DFS(int i, int j)
{
    vis[i][j] = 1;
	for (int k = 0; k < 8; k++)
	{
	    int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (   x >= 0 && x < n 
	    	&& y >= 0 && y < m
			&& vis[x][y] && map[x][y] == '@'
			
			)
		{
			DFS(x, y);
		}
	}
}


/*****************************************************/
int main()
{
    while (cin >> n >> m)
	{
	    if (!n && !m)
		{
		    break;
		}
		for (int i = 0; i < n; i++)
		{
		    cin >> map[i];
		}

		answer = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
		    for (int j = 0; j < m; j++)
			{
			    if (!vis[i][j] && map[i][j] == '@')
				{
				    answer++;
					DFS(i, j);
				}
			}
		}
		cout << answer << endl;
	}
	return 0;
}

// end 
// ism 

