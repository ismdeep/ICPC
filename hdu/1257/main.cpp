/*
最少拦截系统
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 30030

int iMap[MAXN];
int iIndexMap[MAXN];
int iCountMap[MAXN];
int n;

void iDebug()
{
    printf("--debug msg--\n");
}

void iShowMap()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", iMap[i]);
    }
    printf("\n");
}

bool iIsEmpty()
{
    bool yes = true;
    for (int i = 0; yes && i < n; i++)
    {
        //printf("%d ", iMap[i]);
        if (iMap[i] != 0)
        {
            yes = false;
        }
    }
    return yes;
}

void iInit()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &iMap[i]);
    }
}

void iDynamicProgramming()
{
    //iShowMap();
    int iFlag = -1;
    int iCountTmp = 0;
    for (int i = 0; i < n; i++)
    {
        iFlag = -1;
        iCountTmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (iMap[i] < iMap[j] && iCountTmp < iCountMap[j] && iMap[i] != 0 && iMap[j] != 0)
            {
                iFlag = j;
                iCountTmp = iCountMap[j];
            }
        }
        iCountMap[i] = iCountTmp + 1;
        iIndexMap[i] = iFlag;
    }
    iFlag = 0;
    for (int i = 1; i < n; i++)
    {
        if (iCountMap[i] > iCountMap[iFlag])
        {
            iFlag = i;
        }
    }

    /* let's fire */

    while (iIndexMap[iFlag] != -1)
    {
        iMap[iFlag] = 0;
        iFlag = iIndexMap[iFlag];
    }
}
/******************************************************************/
int main()
{
    freopen("in.dat", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        iInit();
        int iSysCount = 0;
        while (!iIsEmpty())
        {
            iDynamicProgramming();
            iSysCount++;
        }
        printf("%d\n", iSysCount);
    }

    return 0;
}

// end
// ism

