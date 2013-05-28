// Project name : 1007 ( Just a Hook ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Tue Aug  7 13:53:26 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Node
{
public:
    int iLeft;
    int iRight;
    int iValue;
};

#ifndef  MAXN
#define MAXN 100000
#endif

Node iMap[MAXN*4];

int n;


/***************************************************************************************/
void iCreateMap(int iStart, int iEnd, int iID)
{
    iMap[iID].iLeft  = iStart;
    iMap[iID].iRight = iEnd;
    if (iStart == iEnd)
    {
        //scanf("%d", iMap[iID].iValue);
        iMap[iID].iValue = 1;
    }
    else
    {
        int iMid;
        iMid = (iStart + iEnd) / 2;
        iCreateMap(iStart,   iMid, iID * 2);
        iCreateMap(iMid + 1, iEnd, iID * 2 + 1);
        iMap[iID].iValue = 1;
    }
}

void iChangeHook(int iStart, int iEnd, int iID, int iValue)
{
    if (iMap[iID].iLeft == iStart && iMap[iID].iRight == iEnd)
    {
        iMap[iID].iValue = iValue;
    }
    else
    {
        int iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
        if (iMap[iID].iValue >= 0)
        {
            iMap[iID*2]  .iValue = iMap[iID].iValue;
            iMap[iID*2+1].iValue = iMap[iID].iValue;
        }
        if (iMid >= iEnd)
        {
            iChangeHook(iStart, iEnd, iID * 2,     iValue);
        }
        else if (iMid + 1 <= iStart)
        {
            iChangeHook(iStart, iEnd, iID * 2 + 1, iValue);
        }
        else
        {
            iChangeHook(iStart,   iMid, iID * 2,     iValue);
            iChangeHook(iMid + 1, iEnd, iID * 2 + 1, iValue);
        }
        iMap[iID].iValue = -1;
    }
}

int iGetHookSum(int iStart, int iEnd, int iID)
{
    int iAnswer = 0;
    int iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
    if (iMap[iID].iValue >= 0)
    {
        iAnswer = iMap[iID].iValue * (iEnd - iStart + 1);
    }
    else
    {
        iAnswer = iGetHookSum(iStart, iMid, iID * 2) + iGetHookSum(iMid + 1, iEnd, iID * 2 + 1);
    }
    return iAnswer;
}

/***************************************************************************************/
int main()
{
    int iT;
    scanf("%d", &iT);
    int iCaseCount;
    for (iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        scanf("%d", &n);
        iCreateMap(1, n, 1);
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int iStart, iEnd, iValue;
            scanf("%d%d%d", &iStart, &iEnd, &iValue);
            iChangeHook(iStart, iEnd, 1, iValue);
        }
        printf("Case %d: The total value of the hook is %d.\n", iCaseCount, iGetHookSum(1, n, 1));
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

