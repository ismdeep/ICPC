// Project name : 5101
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 13:33:26 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int int64;


int main()
{
    int64 num;
    while (cin >> num)
    {
        int64 maxprime = 0;
        int64 stop = sqrt(num);
        for (int i = 2; i <= stop; i++)
        {
            if (num % i == 0)
            {
                maxprime = i;
                while (num % i == 0)
                {
                    num /= i;
                }
            }
        }
        if (num > maxprime)
        {
            maxprime = num;
        }
        cout << maxprime << endl;
    }
    return 0;
}

// end 
// ism 

