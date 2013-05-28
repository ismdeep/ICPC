// Project name : 2478 ( Farey Sequence ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Fri Jul 13 16:30:10 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1000100

typedef unsigned long long int longint;

///////////////////////////////////////////////////////////////////
bool prime[MAXN];
///////////////////////////////////////////////////////////////////
void CInitPrime()
{
    for (int i = 0; i < MAXN; i++)
    {
        prime[i] = true;
    }

    int current_prime = 2;
    for (; current_prime * current_prime <= MAXN; current_prime++)
    {
        if (prime[current_prime] == true)
        {
            for (int i = current_prime * current_prime; i < MAXN; i = i + current_prime)
            {
                prime[i] = false;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////
longint phi[MAXN];
///////////////////////////////////////////////////////////////////
void CInitPhi()
{
    for (int i = 1; i < MAXN; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = i; j < MAXN; j += i)
            {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
///////////////////////////////////////////////////////////////////
int main()
{
    CInitPrime();
    CInitPhi();
    int index;
    while (cin >> index && index)
    {
        longint sum = 0;
        for (int i = 2; i <= index; i++)
        {
            sum += phi[i];
        }
        cout << sum << endl;
    }
    return 0;
}

// end 
// ism 

