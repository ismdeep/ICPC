#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

/*data*/
#define MAXN 3030

int iNumArr[MAXN];
int iMap[MAXN];
int iNumCount;

void iGotNumArr()
{
    for (int i = 0; i < iNumCount; i++)
    {
        scanf("%d", &iNumArr[i]);
    }
}

void iCalOutMap()
{
    for (int i = 0; i < iNumCount - 1; i++)
    {
        iMap[i] = fabs(iNumArr[i] - iNumArr[i+1]);
    }
}

bool iJudge()
{
    int yes = true;
    if (iMap[0] - iMap[1] == 1)
    {
        for (int i = 0; yes && i < iNumCount - 2; i++)
        {
            if (iMap[i] - iMap[i+1] != 1)
            {
                yes = false;
            }
        }
    }
    else if (iMap[0] - iMap[1] == -1)
    {
        for (int i = 0; yes && i < iNumCount - 2; i++)
        {
            if (iMap[i] - iMap[i+1] != -1)
            {
                yes = false;
            }
        }
    }
    else
    {
        yes = false;
    }
    return yes;
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (scanf("%d", &iNumCount) != EOF)
    {
        iGotNumArr();
        iCalOutMap();
        if (iJudge())
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }
}
