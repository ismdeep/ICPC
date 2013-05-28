// Project name : 1183 ( Computing Fast Average ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Thu Aug  9 15:38:43 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

#ifndef MAXN
#define MAXN 100100
#endif

#ifndef CHANGE
#define CHANGE 1
#endif

#ifndef QUERY
#define QUERY 2
#endif

struct Node
{
    int left;
    int right;
    int value;
};

Node iMap[MAXN*4];

int n, k;

/*************************************************************************************/
/* procedure */

void debug()
{
    printf("--debug msg--\n");
}
void iCreatMap(int iStart, int iEnd, int iID)
{
    iMap[iID].left  = iStart;
    iMap[iID].right = iEnd;
    iMap[iID].value = 0;

    if (iStart == iEnd)
    {
        return;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        iCreatMap(iStart, iMid, iID*2);
        iCreatMap(iMid+1, iEnd, iID*2+1);
    }
}

void iChangeValue(int iStart, int iEnd, int iID, int iValue)
{
    if (iMap[iID].left == iStart && iMap[iID].right == iEnd)
    {
        iMap[iID].value = iValue;
    }
    else
    {
        if (iMap[iID].value != -1)
        {
            iMap[iID*2]  .value = iMap[iID].value;
            iMap[iID*2+1].value = iMap[iID].value;
            iMap[iID].value     = -1;
        }
        int iMid = (iMap[iID].left + iMap[iID].right) / 2;
        if (iMid >= iEnd)
        {
            iChangeValue(iStart,   iEnd, iID * 2,     iValue);
        }
        else if (iMid + 1 <= iStart)
        {
            iChangeValue(iStart,   iEnd, iID * 2 + 1, iValue);
        }
        else
        {
            iChangeValue(iStart,   iMid, iID * 2,     iValue);
            iChangeValue(iMid + 1, iEnd, iID * 2 + 1, iValue);
        }
    }
}

int iQuery(int iStart, int iEnd, int iID)
{
    if (iMap[iID].value != -1)
    {
        return (iEnd - iStart + 1) * iMap[iID].value;
    }
    else
    {
        int iMid = (iMap[iID].left + iMap[iID].right) / 2;
        if (iMid >= iEnd)
        {
            return iQuery(iStart, iEnd, iID * 2);
        }
        else if (iMid + 1 <= iStart)
        {
            return iQuery(iStart, iEnd, iID * 2 + 1);
        }
        else
        {
            return iQuery(iStart, iMid, iID * 2) + iQuery(iMid + 1, iEnd, iID * 2 + 1);
        }
    }
}

int iGCD(int a, int b)
{
    int tmp;
    while (b)
    {
        tmp = a % b;
        a   = b;
        b   = tmp;
    }
    return a;
}

void iShowResult(int a, int b)
{
    if (a % b == 0)
    {
        printf("%d\n", a / b);
    }
    else
    {
        int gcd = iGCD(a, b);
        a /= gcd;
        b /= gcd;
        printf("%d/%d\n", a, b);
    }
}
/*************************************************************************************/
/* main */
int main()
{
    int iT;
    scanf("%d", &iT);

    for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        printf("Case %d:\n", iCaseCount);
        scanf("%d%d", &n, &k);
        iCreatMap(0, n-1, 1);

        while (k--)
        {
            int iInstru;
            scanf("%d", &iInstru);
            if (iInstru == CHANGE)
            {
                int iStart;
                int iEnd;
                int iValue;
                scanf("%d%d%d", &iStart, &iEnd, &iValue);
                iChangeValue(iStart, iEnd, 1, iValue);
            }
            if (iInstru == QUERY)
            {
                int iStart;
                int iEnd;
                scanf("%d%d", &iStart, &iEnd);
                int iSum = iQuery(iStart, iEnd, 1);

                // undone
                //printf("%d\n", iSum);
                iShowResult(iSum, iEnd - iStart + 1);
            }
        }

    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

