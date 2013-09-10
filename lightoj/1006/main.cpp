// Project name : 1006 ( Hex-a-bonacci ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Sat Aug 11 14:04:28 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#ifndef MAXN
#define MAXN 10010
#endif

#ifndef MOD
#define MOD 10000007
#endif

typedef unsigned long long longint;

longint iMap[MAXN];

int n;

/*************************************************************************************/
/* procedure */

void iInit()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> iMap[i];
        iMap[i] %= MOD;
    }
    cin >> n;
}

void iCal()
{
    for (int i = 6; i <= n; i++)
    {
        //iMap[i] = iMap[i-1] + iMap[i-2] + iMap[i-3] + iMap[i-4] + iMap[i-5] + iMap[i-6];
        iMap[i] = 0;
        for (int j = 1; j <= 6; j++)
        {
            iMap[i] += iMap[i-j];
            iMap[i] %= MOD;
        }
    }
}

void iShowResult()
{
    cout << iMap[n] << endl;
}
/*************************************************************************************/
/* main */
int main()
{
    int iT;
    cin >> iT;
    for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        cout << "Case " << iCaseCount << ": ";
        iInit      ();
        iCal       ();
        iShowResult();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

