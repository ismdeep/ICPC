// Project name : 4006 ( The kth great number ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul 19 15:06:18 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        multiset<int> a;
        while (n--)
        {
            char chTemp;
            cin >> chTemp;
            if (chTemp == 'I')
            {
                int number;
                cin >> number;
                a.insert(number);
                if (a.size() > k)
                {
                    a.erase(a.begin());
                }
            }
            if (chTemp == 'Q')
            {
                printf("%d\n", *a.begin());
            }
        }
    }
    return 0;
}

// end 
// ism 

