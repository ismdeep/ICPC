#include <iostream>
#include <stdio.h>


/*data*/
#define MAXN 1010
int iMap[MAXN];
int iCount[MAXN];
int iNumCount;

void iDynamicProgramming()
{
    for (int i = 0; i < iNumCount; i++)
    {
        scanf("%d", &iMap[i]);
    }

    iCount[0] = 1;
    for (int i = 1; i < iNumCount; i++)
    {
        int iCountTmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (iMap[j] < iMap[i] && iCount[j] > iCountTmp)
            {
                iCountTmp = iCount[j];
            }
        }
        iCount[i] = iCountTmp+1;
    }
}

void iGotResult()
{
    int iFlag = 0;
    for (int i = 1; i < iNumCount; i++)
    {
        if (iCount[i] > iCount[iFlag])
        {
            iFlag = i;
        }
    }
    printf("%d\n", iCount[iFlag]);
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (scanf("%d", &iNumCount) != EOF)
    {
        iDynamicProgramming();
        iGotResult();
    }

    return 0;
}

// end
// ism
