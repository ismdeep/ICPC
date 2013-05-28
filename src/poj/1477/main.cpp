/*
 * Project     : 1477
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Oct 15 17:02:20 2012 
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

#ifndef MAXN
#define MAXN 1000
#endif

int iHeight[MAXN];
int n;
int i_average;


int move_count;

void init_move_count ()
{
    move_count = 0;
}

void input_iHeight ()
{
    i_average = 0;
    for (int i = 0; i < n; i++)
    {
	cin >> iHeight[i];
	i_average += iHeight[i];
    }
    i_average /= n;
}

void cal_move_count ()
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
	if (iHeight[i] < i_average)
	{
	    for (int j = 0; iHeight[i] < i_average && j < n; j++)
	    {
		if (iHeight[j] > i_average)
		{
		    tmp = (i_average - iHeight[i] > iHeight[j] - i_average) ? iHeight[j] - i_average : i_average - iHeight[i];
		    move_count += tmp;
		    iHeight[i] += tmp;
		    iHeight[j] -= tmp;
		}
	    }
	}
    }
}



int main()
{
    int case_count = 0;
    while (cin >> n && n)
    {
	case_count++;
	cout << "Set #" << case_count << endl;
	cout << "The minimum number of moves is ";
	init_move_count ();
	input_iHeight ();
	cal_move_count ();
	cout << move_count << "." << endl << endl;
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

