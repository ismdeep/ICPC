#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <string.h>
using namespace std;

#define MAP_SIZE 200

int dir_index[8][2] = {
	{-1,  0},
	{ 1,  0},
	{-1,  1},
	{ 1,  1},
	{ 0,  1},
	{-1, -1},
	{ 1, -1},
	{ 0, -1}
};

bool b_map[MAP_SIZE][MAP_SIZE];
int n, m;


void InitMap ()
{
	memset (b_map, 0, sizeof(b_map));
}

void CoverMap (int i, int j)
{
	if (true == b_map[i][j])
	{
		b_map[i][j] = false;
		for (int index = 0; index < 8; index++)
		{
			CoverMap (i + dir_index[index][0], j + dir_index[index][1]);
		}
	}
}

int main ()
{
	while (cin >> n >> m, InitMap(), n + m)
	{
		//---- Input Map ----//
		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++)
			{
				if ('@' == str[j-1])
				{
					b_map[i][j] = true;
				}
			}
		}
		//---- Search & Cover ----//
		int n_count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (true == b_map[i][j])
				{
					n_count++;
					CoverMap (i, j);
				}
			}
		}
		//---- Output Result. ----//
		cout << n_count << endl;
	}
	return 0;
}


