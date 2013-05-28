// Project name : B (shǎ崽 OrOrOrOrz)
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Aug  1 16:50:54 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b ? true : false;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int* iMap;
        iMap = new int[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &iMap[i]);
        }ĺ

        sort(iMap, iMap+n, cmp);

        for (int i = 0; i < ((n-1) / 2) ; i++)
        {
            printf("%d %d ", iMap[i], iMap[n-i-1]);
        }
        if (n % 2 == 0)
        {
            printf("%d %d\n", iMap[(n/2)-1],iMap[n/2]);
        }
        else
        {
            printf("%d\n",    iMap[n/2]);
        }
    }
    return 0;
}

// end
// ism
