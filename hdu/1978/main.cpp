#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MAXN 110
#define MOD  10000

/**********************************************************/
int count_map[MAXN][MAXN];

int iMap[MAXN][MAXN];
int sum[MAXN][MAXN];

int n, m;

/**********************************************************/

bool point_can_go(int x, int y)
{
	if (
		(x >= 1 && x <= n)
	&&  (y >= 1 && y <= m)
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void _make_count_map()
{
	memset(count_map, 0, sizeof(count_map));
	//
	//
	// init first line and first row
	for (int j = 1; j < MAXN; j++)
	{
		count_map[1][j] = 1;
	}
	for (int i = 2; i < MAXN; i++)
	{
		count_map[i][1] = i;
	}
	//
	//
	// init for other data in count_map
	for (int i = 2; i < MAXN; i++)
	{
		for (int j = 2; j < MAXN; j++)
		{
			count_map[i][j] = count_map[i][j-1] + count_map[i-1][j];
		}
	}
}

void _show_count_map()
{
	// just for debug
	//
	//
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << count_map[i][j] << " ";
		}
		cout << endl;
	}
}

void set_value()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> iMap[i][j];
		}
	}
	//
	//
	// for debug 
	// output iMap[][]
	/*
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << iMap[i][j] << " ";
		}
		cout << endl;
	}
	*/
}

void set_sum_map()
{
	sum[n][m] = 1;
	for (int index_j = m-1; index_j >= 1; index_j--)
	{
		//
		//
		/* i , j are current pointer that will be used next */
		int i, j;
		i = n;
		j = index_j;
		//
		//
		while (point_can_go(i, j))
		{
			int i_end = i + iMap[i][j];
			int j_end = j + iMap[i][j];
			//
			//
			//
			int tmp_sum = 0;
			int x, y;
			x = i;
			for (y = j + 1; y <= j_end; y++)
			{
				if (point_can_go(x, y) && ((x + y) <= (i + j + iMap[i][j])))
				{
					tmp_sum += (sum[x][y]*count_map[x-i+1][y-j+1]);
					tmp_sum %= MOD;
				}
			}
			for (x = i + 1; x <= i_end; x++)
			{
				for (y = j; y <= j_end; y++)
				{
					if (point_can_go(x, y) && ((x + y) <= (i + j + iMap[i][j])))
					{
						tmp_sum += (sum[x][y]*count_map[x-i+1][y-j+1]);
						tmp_sum %= MOD;
					}
				}
			}
			sum[i][j] = tmp_sum;
			//
			//
			//
			//
			//
			//
			i--;
			j++;
		}
	}
	for (int index_i = m - 1; index_i >= 1; index_i--)
	{
		int i, j;
		i = index_i;
		j = 1;
		//
		//
		while (point_can_go(i, j))
		{
			int i_end = i + iMap[i][j];
			int j_end = j + iMap[i][j];
			//
			//
			//
			int tmp_sum = 0;
			int x, y;
			x = i;
			for (y = j + 1; y <= j_end; y++)
			{
				if (point_can_go(x, y) && ((x + y) <= (i + j + iMap[i][j])))
				{
					tmp_sum += (sum[x][y]*count_map[x-i+1][y-j+1]);
					tmp_sum %= MOD;
				}
			}
			for (x = i + 1; x <= i_end; x++)
			{
				for (y = j; y <= j_end; y++)
				{
					if (point_can_go(x, y) && ((x + y) <= (i + j + iMap[i][j])))
					{
						tmp_sum += (sum[x][y]*count_map[x-i+1][y-j+1]);
						tmp_sum %= MOD;
					}
				}
			}
			sum[i][j] = tmp_sum;
			//
			//
			//
			i--;
			j++;
		}
	}
	cout << sum[1][1] << endl;
}

/**********************************************************/
int main()
{
	_make_count_map();
	//_show_count_map();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		set_value();
		set_sum_map();
	}
	return 0;
}
// end 
// iCoding

