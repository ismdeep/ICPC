// Project name : 1093
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Aug  4 23:36:43 2012


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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }

        cout << sum << endl;
    }
    return 0;
}

// end 
// ism 

