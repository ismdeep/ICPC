// Project name : 5102
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 14:53:54 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 gcd(int64 a, int64 b)
{
    while (b)
    {
        int64 tmp;
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int64 a, b;
    while (cin >> a >> b)
    {
        cout << gcd(a, b) << endl;
    }
    return 0;
}

// end 
// ism 

