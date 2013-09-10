#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 50050

struct Node
{
    int iLeft;
    int iRight;
    int iNum;
};

Node iMap[MAXN*3];
int n;
void iCreatMap(int iStart, int iEnd, int iID)
{
    iMap[iID].iLeft  = iStart;
    iMap[iID].iRight = iEnd;
    if (iStart == iEnd)
    {
        scanf("%d", &iMap[iID].iNum);
    }
    else
    {
        int iMid;
        iMid = (iStart + iEnd) / 2;
        iCreatMap(iStart,   iMid, iID * 2);
        iCreatMap(iMid + 1, iEnd, iID * 2 + 1);
        iMap[iID].iNum = iMap[iID*2].iNum + iMap[iID*2+1].iNum;
    }
}

int iQuery(int iStart, int iEnd, int iID)
{
    if (iStart == iMap[iID].iLeft && iEnd == iMap[iID].iRight)
    {
        return iMap[iID].iNum;
    }
    else
    {
        int iMid;
        iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
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

int iFlag;
int iValue;

void iAdd(int iID)
{
    if (iMap[iID].iLeft == iFlag && iMap[iID].iRight == iFlag)
    {
        iMap[iID].iNum += iValue;
    }
    else
    {
        int iMid;
        iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
        if (iMid >= iFlag)
        {
            iAdd(iID*2);
        }
        else
        {
            iAdd(iID*2+1);
        }
        iMap[iID].iNum = iMap[iID*2].iNum + iMap[iID*2+1].iNum;
    }
}

void iSub(int iID)
{
    if (iMap[iID].iLeft == iFlag && iMap[iID].iRight == iFlag)
    {
        iMap[iID].iNum -= iValue;
    }
    else
    {
        int iMid;
        iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
        if (iMid >= iFlag)
        {
            iSub(iID*2);
        }
        else
        {
            iSub(iID*2+1);
        }
        iMap[iID].iNum = iMap[iID*2].iNum + iMap[iID*2+1].iNum;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    int iCaseCount;
    for (iCaseCount = 1; iCaseCount <= t; iCaseCount++)
    {
        scanf("%d", &n);
        printf("Case %d:\n", iCaseCount);
        iCreatMap(1, n, 1);
        string iInstruction;
        while (cin >> iInstruction && iInstruction != "End")
        {
            if (iInstruction == "Query")
            {
                int iStart, iEnd;
                scanf("%d%d", &iStart, &iEnd);
                printf("%d\n", iQuery(iStart, iEnd, 1));
            }
            if (iInstruction == "Add")
            {
                scanf("%d%d", &iFlag, &iValue);
                iAdd(1);
            }
            if (iInstruction == "Sub")
            {
                scanf("%d%d", &iFlag, &iValue);
                iSub(1);
            }
        }
    }

    return 0;
}

// end
// ism
