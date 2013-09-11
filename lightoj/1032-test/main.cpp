// Project name : 1032-test ( Fast Bit Calculations ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Sat Aug 11 15:24:46 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

#ifndef MAXN
#define MAXN 100
#endif

/*************************************************************************************/
/* procedure */

void iCal(int iNum)
{
    printf("%10d -- ", iNum);

    int iMap[16];
    for (int i = 0; i < 16; i++)
    {
        iMap[i] = 0;
    }

    int iTop = -1;
    while (iNum)
    {
        iTop++;
        iMap[iTop] = iNum % 2;
        iNum /= 2;
    }

    for (int i = 15; i >= 0; i--)
    {
        cout << iMap[i];
    }

    /* cal */
    int iCount = 0;
    for (int i = 0; i <= 14; i++)
    {
        if (iMap[i] == 1 && iMap[i+1] == 1)
        {
            iCount++;
        }
    }

    printf("  ---  %d\n", iCount);

}

/*************************************************************************************/
/* main */
int main()
{
    for (int iNum = 0; iNum <= MAXN; iNum++)
    {
        iCal(iNum);
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

