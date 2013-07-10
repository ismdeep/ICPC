// Project name : D ( Distinct Primes ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 14:04:18 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

#ifndef MAXN
#define MAXN 2000
#endif

bool iIsPrime[MAXN*MAXN];

int iMap[MAXN];
int iTop;
/*************************************************************************************/
/* procedure */

void debug()
{
    cout << "--" << endl;
}

bool iIsLuckyNumber(int iNum)
{
    int count = 0;
    int i = 2;
    while (iNum > 1)
    {
        if (iNum % i == 0)
        {
            count++;
            while (iNum % i == 0)
            {
                iNum /= i;
            }
        }
        else
        {
            i++;
            while (!iIsPrime[i])
            {
                i++;
                //cout << i << endl;
            }
        }
    }
    return count >= 3 ? true : false;
}

void iMakeMap()
{
    iTop = 0;
    int iNum = 30;
    while (iTop <= MAXN)
    {
        if (iIsLuckyNumber(iNum))
        {
            iTop++;
            iMap[iTop] = iNum;
        }
        iNum++;
    }
}

void iMakePrime()
{
    for (int i = 0; i < MAXN * MAXN; i++)
    {
        iIsPrime[i] = true;
    }
    iIsPrime[0] = false;
    iIsPrime[1] = false;

    for (int i = 2; i * i < MAXN; i++)
    {
        if (iIsPrime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                iIsPrime[j] = false;
            }
        }
    }
}

void iShowMap()
{
    for (int i = 1; i <= MAXN; i++)
    {
        cout << iMap[i] << endl;
    }
}
/*************************************************************************************/
/* main */
int main()
{
    iMakePrime();
    iMakeMap();
    //iShowMap();

    int iT;
    cin >> iT;
    while (iT--)
    {
        int n;
        cin >> n;
        cout << iMap[n] << endl;
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

