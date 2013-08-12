#include <iostream>
#include <stdio.h>

#define MAXN 200200

void debug()
{
    printf("--debug msg--\n");
}

int n, m;
int iMap[MAXN*4];

int iCalMax(int a, int b)
{
    return a > b ? a : b ;
}

void iCreator(int iStart, int iEnd, int iID)
{
    if (iStart == iEnd)
    {
        int iTmp;
        scanf("%d", &iTmp);
        iMap[iID] = iTmp;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        iCreator(iStart, iMid, iID*2);
        iCreator(iMid+1, iEnd, iID*2+1);
        iMap[iID] = iCalMax (iMap[iID*2] , iMap[iID*2+1]);
    }
}

void iChangeScore(int iStart, int iEnd, int iID, int iFlag, int iScore)
{
    if (iStart == iEnd)
    {
        iMap[iID] = iScore;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        if (iMid >= iFlag)
        {
            iChangeScore(iStart, iMid, iID*2,   iFlag, iScore);
        }
        else
        {
            iChangeScore(iMid+1, iEnd, iID*2+1, iFlag, iScore);
        }
        iMap[iID] = iCalMax( iMap[iID*2] , iMap[iID*2+1]);
    }
}

int iQuery(int iStart, int iEnd, int iID, int iStartQuery, int iEndQuery)
{
    if (iStart == iStartQuery && iEnd == iEndQuery)
    {
        return iMap[iID];
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        if (iMid >= iEndQuery)
        {
            return iQuery(iStart, iMid, iID*2,   iStartQuery, iEndQuery);
        }
        else if (iMid+1 <= iStartQuery)
        {
            return iQuery(iMid+1, iEnd, iID*2+1, iStartQuery, iEndQuery);
        }
        else
        {
            return iCalMax(iQuery(iStart, iMid, iID*2,   iStartQuery, iMid)
                 , iQuery(iMid+1, iEnd, iID*2+1, iMid+1,      iEndQuery)
                           );
        }
    }
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        //printf("%d %d\n", n, m);
        //debug();
        iCreator(1, n, 1);
        for (int i = 0 ; i < m; i++)
        {
            char iInstruction;
            getchar();
            scanf("%c", &iInstruction);
            if (iInstruction == 'U')
            {
                int iFlag, iScore;
                scanf("%d%d", &iFlag, &iScore);
                iChangeScore(1, n, 1, iFlag, iScore);
            }
            if (iInstruction == 'Q')
            {
                int iStart, iEnd;
                scanf("%d%d", &iStart, &iEnd);
                printf("%d\n", iQuery(1, n, 1, iStart, iEnd));
            }
        }
    }
    return 0;
}

// end
// ism
