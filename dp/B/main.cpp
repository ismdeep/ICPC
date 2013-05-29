// Project name : B
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Jul 14 19:34:01 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 110

int a[MAXN][MAXN];

int n;

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
}

void dp()
{
    for (int i = n -2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[i+1][j] > a[i+1][j+1])
            {
                a[i][j] += a[i+1][j];
            }
            else
            {
                a[i][j] += a[i+1][j+1];
            }
        }
    }
}


int main()
{
    while (cin >> n)
    {
        init();
        dp();
        cout << a[0][0] << endl;
    }
    return 0;
}

// end 
// ism 

