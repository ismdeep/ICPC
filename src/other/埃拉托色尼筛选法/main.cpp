// Project name : 埃拉托色尼筛选法
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul 15 09:40:26 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n >= 2)
    {
        int stop = sqrt(n);
        bool* prime = new bool[n+1];

        for (int i = 2; i <= n; i++)
        {
            prime[i] = true;
        }

        for (int i = 2; i  <= stop; i++)
        {
            if (prime[i] == true)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                cout << i << " ";
            }
        }
        cout << endl << endl << endl;

        delete[] prime;
    }
    return 0;
}

// end 
// ism 

