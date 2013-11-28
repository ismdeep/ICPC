// Project name : GCD
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 11 16:25:50 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp;
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << gcd(a, b) << endl;
    }
    return 0;
}

// end 
// ism 

