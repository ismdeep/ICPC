// Project name : 1787 ( GCD Again ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 17 15:38:12 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long int longint;


longint phi(longint num)
{
    longint sum = 1;
    for (long int i = 2; i <= sqrt((double long)num); i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
            {
                sum *= i;
                num /= i;
            }
            sum /= i;
            sum *= (i - 1);
        }
    }

    if (num != 1)
    {
        sum *= (num - 1);
    }

    return sum;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        cout << n - 1 - phi(n) << endl;
    }
    
    return 0;
}

// end 
// ism 

