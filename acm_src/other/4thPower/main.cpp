// Project name : 4thPower
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Jul 14 14:37:29 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int int64;

#define MAXN 100000

int main()
{
    int64* a;
    a = new int64[MAXN + 1];

    for (int64 i = 1; i <= MAXN; i++)
    {
        a[i] = i * i * i;
    }

    // output for test if it's overflow
    //cout << a[MAXN] << endl;
    //return 0;

    int pow_count = 3;
    for (int64 i = 1; i <= MAXN; i++)
    {
        for (int64 j = 1; j <= MAXN; j++)
        {
            for (int64 k = 1; k <= MAXN; k++)
            {
                if (a[i] + a[j] == a[k] && i <= j)
                {
                    cout         << i << "^" << pow_count 
                        << " + " << j << "^" << pow_count
                        << " = " << k << "^" << pow_count 
                        << endl;
                }
            }
        }
    }
    return 0;
}

// end 
// ism 

