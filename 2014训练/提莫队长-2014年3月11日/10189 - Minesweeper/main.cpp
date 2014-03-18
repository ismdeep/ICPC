/* 
 * Project Name : 10189
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Mon Mar 17 10:15:10 2014 
 * 
 * */ 
#include <set> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

#define _ISM_DEBUG_ 

#define MAXN 102
#define BLANK 0
#define BLOCK -1


int map[MAXN][MAXN];
int n,m;

int dir[8][2] = {
	{  1, -1},
	{  1,  1},
	{  1,  0},
	{  0, -1},
	{  0,  1},
	{ -1, -1},
	{ -1,  1},
	{ -1,  0}
};


// ----- just init the map set, all this code are just shit
// ----- in this program.
void init_map_set()
{
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			map[i][j] = BLANK;
		}
	}
}


//---- This is the WTF, what the fuck main function.
int main ()
{
	bool shit_flag = false;
	int map_set_index = 0;
	while (cin >> n >> m, n+m)
	{
		if (shit_flag)
		{
			cout << endl;
		}
		shit_flag = true;
		map_set_index++;
		init_map_set ();
		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++)
			{
				if (str[j-1] == '*')
				{
					map[i][j] = BLOCK;
				}
			}
		}
		// --- count it 
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == BLANK)
				{
					int count_tmp = 0;
					for (int k = 0; k < 8; k++)
					{
						if (map[i+dir[k][0]][j+dir[k][1]] == BLOCK)
						{
							count_tmp++;
						}
					}
					map[i][j] = count_tmp;
				}
			}
		}
		cout << "Field #" << map_set_index << ":" << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == BLOCK)
				{
					cout << "*";
				}
				else
				{
					cout << map[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}


// end 
// ismdeep
// xTarget
// 
