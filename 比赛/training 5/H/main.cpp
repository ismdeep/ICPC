/*
 * Project     : H
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Oct 21 11:28:43 2012 
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

#define MAXN 110
#define MAXM 2200

bool iMap[MAXN][MAXM];
int n, m;

void show_iMap ()
{
    for (int i = 1; i <= n; i++)
    {
	for (int j = 1; j <= m; j++)
	{
	    if (iMap[i][j])
	    {
		cout << "1";
	    }
	    else
	    {
		cout << "0";
	    }
	}
	cout << endl;
    }
}

int iABS (int num)
{
    if (num >= 0)
    {
	return num;
    }
    else
    {
	return 0 - num;
    }
}

void init_iMap ()
{
    for (int i = 0; i < MAXN; i++)
    {
	for (int j = 0; j < MAXM; j++)
	{
	    iMap[i][j] = false;
	}
    }
}

void intput_iMap ()
{
    for (int i = 1; i <= n * n; i++)
    {
	int x, y;
	// cin >> x >> y;
	scanf ("%d%d", &x, &y);
        iMap[x][y] = true;
    }
}

int cal_move_count (int index)
{
    int tmp_move_count = 0;
    int tmp_index;
    for (int i = 1; i <= n; i++)
    {
	tmp_index = index;
	for (int j = 1; j <= m; j++)
	{
	    if (iMap[i][j] == true)
	    {
		tmp_move_count += iABS(tmp_index - j);
		tmp_index++;
	    }
	}
    }
    // cout << tmp_move_count << endl;
    return tmp_move_count;
}

int main()
{
    while (cin >> n >> m)
    {
	if (0 == n || 0 == m)
	{
	    break;
	}
	init_iMap ();
	intput_iMap ();
	// show_iMap ();
	int move_count = 0x3fffffff;
	for (int index = 1; index <= (m - n + 1); index++)
	{
	    int tmp_move_count;
	    tmp_move_count = cal_move_count (index);
	    if (tmp_move_count < move_count)
	    {
		move_count = tmp_move_count;
	    }
	}
	cout << move_count << endl;
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

