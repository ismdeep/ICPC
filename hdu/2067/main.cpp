// Project name : 2067 ( 小兔的棋盘 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul 12 14:35:03 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long int map[40][40];

void CInitMap()
{
    for (int i = 0; i < 40; i++)
    {

        for (int j = 0; j < 40; j++)
        {
            map[i][j] = 0;
        }
    }

    for (int i = 1; i < 40; i++)
    {
        map[1][i] = 1;
    }

    for (int i = 2; i < 40; i++)
    {
        for (int j = i; j < 40; j++)
        {
            map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
}

int main()
{
    CInitMap();

    int count = 0;
    int n;
    while (cin >> n && n != -1)
    {
        count++;
        cout << count << " " << n << " ";
        cout << 2 * map[n+1][n+1] << endl;
    }
    return 0;
}

// end 
// ism 

