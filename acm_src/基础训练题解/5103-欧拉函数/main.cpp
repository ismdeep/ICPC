// Project name : 5103-欧拉函数
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 15:19:08 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 phi(int64 num)
{
    int64 sum = 1;
    for (int64 i = 2; i <= sqrt(num); i++)
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
    int64 number;
    while (cin >> number)
    {
        cout << phi(number) << endl;
    }
    return 0;
}

// end 
// ism 

