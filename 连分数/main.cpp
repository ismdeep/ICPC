// Project name : 连分数
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul 15 10:35:11 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && a != 0 && b != 0)
    {
        while (b)
        {
            int tmp = a % b;
            cout << a / (b) << " ";
            a = b;
            b = tmp;
        }

        cout << endl;
    }
    return 0;
}

// end 
// ism 

