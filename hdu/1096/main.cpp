// Project name : 1096
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Aug  4 23:46:02 2012


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
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << endl;
        if (k != t - 1)
        {
            cout << endl;
        }
    }
    return 0;
}

// end 
// ism 

