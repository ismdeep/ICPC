// Project name : 102
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 10:45:51 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int mod(int k, int x, int c)
{
    int a = 1;
    long long int r = k;
    while (x)
    {
        if (x & 1)
        {
            a = (a * r) % c;
        }
        r = ((r % c) * (r % c)) % c;
        x = x >> 1;
    }
    return a;
}

int main()
{
    int n, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        cout << mod(a, b, c) << endl;
    }
    
    return 0;
}

// end 
// ism 

