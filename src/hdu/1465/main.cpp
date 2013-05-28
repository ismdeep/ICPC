// Project name : 1465 ( 不容易系列之一 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul 19 16:31:01 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int longint;

longint a[30];

void init()
{
    a[2] = 1;
    a[3] = 2;
    for (int i = 4; i < 30; i++)
    {
        a[i] = (i-1) * (a[i-1] + a[i-2]);
    }
}
int main()
{
    init();
    
    int n;
    while (cin >> n)
    {
        cout << a[n] << endl;
    }
    return 0;
}

// end 
// ism 

