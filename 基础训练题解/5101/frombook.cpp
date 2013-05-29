#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


typedef long long int __int64;

int main()
{

    __int64 number,limit,maxnumber;
    cin >> number;
    maxnumber = 0;
    limit = (__int64)sqrt(number);
    for (int i = 2; i <= limit; i++)
    {
        if (number % i == 0)
        {
            maxnumber = i;
            while (number % i == 0)
            {
                number /= i;
            }
        }
    }
    if (maxnumber == 0)
    {
        maxnumber = number;
    }
    cout << maxnumber << endl;
    return 0;
}

// end 
// ism 
//
