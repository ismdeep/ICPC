// Project name : I ( Lucky Division ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 12:40:15 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#define MAXN 2000
bool iIsAlmostLucky[MAXN];

/*************************************************************************************/
/* procedure */

bool iIsLucky(int iNum)
{
    bool iFlag = true;
    while (iNum && iFlag)
    {
        if (iNum % 10 == 4 || iNum % 10 == 7)
        {
            iFlag = true;
        }
        else
        {
            iFlag = false;
        }
        iNum /= 10;
    }
    return iFlag;
}

void iMakeIsAlmostLucky()
{
    iIsAlmostLucky[0] = false;
    iIsAlmostLucky[1] = false;

    for (int i = 2; i < MAXN; i++)
    {
        iIsAlmostLucky[i] = false;
    }

    for (int i = 2; i < MAXN; i++)
    {
        if (iIsLucky(i))
        {
            for (int j = 1; j * i < MAXN; j++)
            {
                iIsAlmostLucky[j*i] = true;
            }
        }
    }
}

/*************************************************************************************/
/* main */
int main()
{
    iMakeIsAlmostLucky();
    int n;
    while (cin >> n)
    {
        if (iIsAlmostLucky[n])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

