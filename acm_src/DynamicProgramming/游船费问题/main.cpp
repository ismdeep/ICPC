// Project name : 游船费问题
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Jul 14 15:21:28 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 110

int a[MAXN][MAXN];

int n;
///////////////////////////////////////////////////////////////////////////////
void dp()
{
    // dp .. - - > > that's very important for this program
    for (int j = 2; j <= n; j++)
    {
        int min = a[1][j];
        for (int i = 2; i < j; i++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
            }
        }

        if ((a[0][j-1] + min) < a[0][j])
        {
            a[0][j] = a[0][j-1] + min;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
void init()
{
    // set all mem to 0
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    // input data to a[][]
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
void output()
{
    cout << a[0][n] << endl;
}

int main()
{
    int time = 0;
    while (cin >> n)
    {
        init();
        dp();
        time++;
        cout << "Case " << time << ":" << endl;
        output();
    }
    return 0;
}

// end 
// ism 

