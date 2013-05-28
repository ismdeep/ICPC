// Project name : 2407 ( Relatives ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 16:13:57 2012


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
    for (longint i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
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
    longint number;
    while (cin >> number && number)
    {
        cout << phi(number) << endl;
    }
    return 0;
}

// end 
// ism 

