// Project name : 3501 ( Calculation 2 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 17:14:43 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////
typedef unsigned long long int longint;
////////////////////////////////////////////////////////////////////////
longint phi(longint num)
{
    longint sum = 1;
    for (longint i = 2; i <= sqrt((double long)num); i++)
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
////////////////////////////////////////////////////////////////////////
int main()
{
    longint number;
    while (cin >> number && number)
    {
        cout << ((number - 1) * number / 2 - number * phi(number) / 2) % 1000000007 << endl;
    }
    return 0;
}

// end 
// ism 

