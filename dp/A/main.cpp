// Project name : A ( Longest Ordered Subsequence ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Jul 14 19:57:59 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1100

int a[MAXN];
int n;

void init()
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void dp()
{
    int* tmp;
    tmp = new int[n];
    tmp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int tmp_max = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (tmp_max < tmp[j])
                {
                    tmp_max = tmp[j];
                }
            }
        }

        tmp[i] = tmp_max + 1;
    }

    // output for result
    int max = tmp[0];
    for (int i = 1; i < n; i++)
    {
        if (max < tmp[i])
        {
            max = tmp[i];
        }
    }
    cout << max << endl;
}


int main()
{
    while (cin >> n)
    {
        init();
        dp();
    }
    return 0;
}

// end 
// ism 

