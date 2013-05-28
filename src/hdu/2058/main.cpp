// Project name : 2058 ( The sum problem ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul 15 14:45:01 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n + m)
    {
        int length = sqrt((double)2 * m) + 2;

        while (length)
        {
            int a = m / length - (length - 1) / 2;
            if ((a + a + length - 1) * length / 2 == m && a > 0 && (a + length - 1) <= n)
            {
                printf("[%d,%d]\n", a, a + length - 1);
            }
            length--;
        }
        cout << endl;
    }
    return 0;
}

// end 
// ism 

