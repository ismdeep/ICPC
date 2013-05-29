// Project name : 1953
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 14:40:58 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long int longint;

longint a[50];

void init()
{
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i < 50; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    for (int count = 1; count <= t; count++)
    {
        int n;
        cin >> n;
        cout << "Scenario #" << count << ":" << endl << a[n] << endl << endl;
    }
    return 0;
}

// end 
// ism 

