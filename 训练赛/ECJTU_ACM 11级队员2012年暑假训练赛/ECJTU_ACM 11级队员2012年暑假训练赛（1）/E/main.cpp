#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
    public:
    int iSum;
    int iIndex;
};

#define MAXN 100010

Node iMap[MAXN];
int n;

void iInit()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &iMap[i].iSum);
        iMap[i].iIndex = i;
    }
}

void iDynamicProgramming()
{
    for (int i = 1; i < n; i++)
    {
        if (iMap[i-1].iSum >= 0)
        {
            iMap[i].iSum   += iMap[i-1].iSum;
            iMap[i].iIndex  = iMap[i-1].iIndex;
        }
    }
}

void iShowGreatest(int iCaseID)
{
    int iFlag = 0;
    for (int i = 1; i < n; i++)
    {
        if (iMap[i].iSum > iMap[iFlag].iSum)
        {
            iFlag = i;
        }
    }
    if (iCaseID != 1)
    {
        printf("\n");
    }
    printf("Case %d:\n%d %d %d\n", iCaseID, iMap[iFlag].iSum, iMap[iFlag].iIndex+1, iFlag+1);
}



// --- start
int main()
{
    //freopen("in.dat", "r", stdin);
    int t;
    scanf("%d", &t);
    int iCaseID;
    for (iCaseID = 1; iCaseID <= t; iCaseID++)
    {
        iInit();
        iDynamicProgramming();
        iShowGreatest(iCaseID);
    }

    return 0;
}

// end
// iCoding@CodeLab
