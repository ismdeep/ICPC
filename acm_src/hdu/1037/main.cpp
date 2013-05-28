// Project name : 1037 ( Keep on Truckin ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 11:55:28 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        bool nocrash = true;
        if (a <= 168)
        {
            cout << "CRASH " << a << endl;
            nocrash = false;
        }
        if (b <= 168)
        {
            cout << "CRASH " << b << endl;
            nocrash = false;
        }
        if (c <= 168)
        {
            cout << "CRASH " << c << endl;
            nocrash = false;
        }
        if (nocrash)
        {
            cout << "NO CRASH" << endl;
        }
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

