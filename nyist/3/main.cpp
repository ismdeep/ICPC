// Project name : 3
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 11:04:42 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double a, b, tmp;
        a = 0.0;
        b = 0.0;

        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a += tmp;
            cin >> tmp;
            b += tmp;
        }

        a /= n;
        b /= n;

        printf("%.3f %.3f\n", a, b);
    }
    return 0;
}

// end 
// ism 

