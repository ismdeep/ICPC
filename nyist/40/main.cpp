// Project name : 40 ( 公约数与公倍数 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 17 16:20:43 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int longint;

longint gcd(longint a, longint b)
{
    int tmp;
    while (b)
    {
        tmp = a % b;
        a   = b;
        b   = tmp;
    }

    return a;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        int tmp = gcd(n, m);

        printf("%d %d\n", tmp, (n * m / tmp));
    }
    return 0;
}

// end 
// ism 

