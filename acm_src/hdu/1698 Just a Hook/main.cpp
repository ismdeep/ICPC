#include <iostream>
#include <stdio.h>
using namespace std;

/***************************************************/
class Node
{
public:
    int iL;
    int iR;
    int iValue;
    int iID;
};

#define MAXN 100010

Node iMap[MAXN*4];
int n;
/***************************************************/
void debug()
{
    printf("--debug msg--\n");
}

void debugShowMap()
{
    for (int i = 0; i < n * 3; i++)
    {
        printf("%d ", iMap[i].iValue);
    }
    printf("\n");
}
void iMakeMap(int iStart, int iEnd, int iID)
{
    iMap[iID].iID = iID;
    iMap[iID].iL  = iStart;
    iMap[iID].iR  = iEnd;
    if (iStart == iEnd)
    {
        iMap[iID].iValue = 1;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        iMakeMap(iStart,   iMid, iID * 2);
        iMakeMap(iMid + 1, iEnd, iID * 2 + 1);
        iMap[iID].iValue = iMap[iID*2].iValue + iMap[iID*2+1].iValue;
    }
}

void iCoverHook(const int iStart, const int iEnd, const int iID, const int iValue)
{
    if (iStart == iEnd && iStart == iMap[iID].iR && iStart == iMap[iID].iL)
    {
        iMap[iID].iValue = iValue;
    }
    else
    {
        int iMid;
        iMid = (iMap[iID].iL + iMap[iID].iR) / 2;
        if (iMid >= iEnd)
        {
            iCoverHook(iStart, iEnd, iID * 2,     iValue);
        }
        else if (iMid + 1 <= iStart)
        {
            iCoverHook(iStart, iEnd, iID * 2 + 1, iValue);
        }
        else
        {
            iCoverHook(iStart,   iMid, iID * 2,     iValue);
            iCoverHook(iMid + 1, iEnd, iID * 2 + 1, iValue);
        }
        iMap[iID].iValue = iMap[iID*2].iValue + iMap[iID*2+1].iValue;
    }
    //iMap[iID].iValue = iMap[iID*2].iValue + iMap[iID*2+1].iValue;
}

/***************************************************/
int main()
{
    //freopen("in.dat", "r", stdin);
    int iT;
    scanf("%d", &iT);
    int iCaseCount;
    for (iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        scanf("%d", &n);
        iMakeMap(1, n, 1);
        int iTime;
        scanf("%d", &iTime);
        //debugShowMap();
        while (iTime--)
        {
            int iStart, iEnd, iValue;
            scanf("%d%d%d", &iStart, &iEnd, &iValue);
            iCoverHook(iStart, iEnd, 1, iValue);
            //debugShowMap();
        }
        printf("Case %d: The total value of the hook is %d.\n", iCaseCount, iMap[1].iValue);
    }
    return 0;
}

// end
// ism
