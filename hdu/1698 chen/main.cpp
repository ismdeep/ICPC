#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void debug()
{
    printf("--debug msg--\n");
}

struct Hook
{
    int iLeft;
    int iRight;
    int iCount;
};

Hook iMap[300100];
int n;

void iInit(int x, int y, int iID)
{
    if (iMap[iID].iLeft == 0 && iMap[iID].iRight == 0)
    {
        iMap[iID].iLeft  = x;
        iMap[iID].iRight = y;
        iMap[iID].iCount = 1;
    }

    if (x == y)
    {
        return;
    }
    int iMid = (x + y) / 2;
    iInit(x,      iMid, iID * 2);
    iInit(iMid+1, y,    iID * 2 + 1);
}

void iInsert(int x, int y, int iID, int key)
{
    if (iMap[iID].iCount == key)
    {
        return ;
    }
    if (iMap[iID].iLeft == x && iMap[iID].iRight == y)
    {
        iMap[iID].iCount = key;
        return ;
    }
    if (iMap[iID].iCount != -1)
    {
        iMap[iID*2].iCount = iMap[iID*2+1].iCount = iMap[iID].iCount;
        iMap[iID].iCount   = -1;
    }
    int iMid = (iMap[iID].iLeft + iMap[iID].iRight) / 2;
    if (y <= iMid)
    {
        iInsert(x, y, iID*2, key);
    }
    else
    {
        if (x > iMid)
        {
            iInsert(x, y, iID * 2 + 1, key);
        }
        else
        {
            iInsert(x,      iMid, iID * 2,     key);
            iInsert(iMid+1, y,    iID * 2 + 1, key);
        }
    }
}

int iSearch(int i)
{
    if (iMap[i].iCount != -1)
    {
        return (iMap[i].iRight - iMap[i].iLeft + 1) * (iMap[i].iCount);
    }
    else
    {
        return iSearch(i*2) + iSearch(i*2+1);
    }
}
int main()
{
    //freopen("in.dat", "r", stdin);
    int t;
    scanf("%d",&t);
    int tt=1;
    while(t--)
    {
        scanf("%d",&n);
        iInit(1,n,1);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int x,y,key;
            scanf("%d%d%d",&x,&y,&key);
            iInsert(x,y,1,key);
        }
        printf("Case %d: The total value of the hook is %d.\n",tt,iSearch(1));
        tt++;
        memset(iMap,0,sizeof(iMap));
    }
    return 0;
}

