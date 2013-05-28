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

#define INT_MAX 0x3fffffff

const int N = 222;
int iSum[N][N], iCount[N], n, m, n2;

void init_data ()
{
    memset (iCount, 0, sizeof (iCount));
}

void input_data ()
{
    for (int i = 1; i <= n * n; i++)
    {
	int x, y;
	cin >> x >> y;
	x--;
	y--;
	iSum[x][iCount[x]++] = y;
    }
}

void sort_data ()
{
    for (int i = 0; i < n; i++)
    {
	sort (iSum[i], iSum[i] + n);
    }
}

int iMin (int a, int b)
{
    return (a < b) ? a : b;
}

int cal_move_count (int index)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
	for (int k = 0; k < n; k++)
	{
	    sum += abs (iSum[j][k] - (index + k));
	}
    }
    return sum;
}

int main()
{
    while (cin >> n >> m && n + m)
    {
        init_data ();
	input_data ();
	sort_data ();
        int right_index = m - n;
	int result = INT_MAX;
        for (int index = 0; index <= right_index; index++)
        {
            int tmp_move_count = cal_move_count (index);
            result = iMin(result, tmp_move_count);
        }
        cout << result << endl;
    }
    return 0;
}

// end
// iCoding
