#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define MAXN 6000

int iMap[MAXN][MAXN];

void iInitMap()
{
    memset(iMap, 0, sizeof(iMap));
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 1; j < MAXN; j++)
        {
            if ((i*j-1) % (i+j) == 0)
            {
                iMap[i][j] = (i*j-1) / (i+j);
            }
        }
    }
}

void iShowMap()
{
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            printf("%d ", iMap[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("in.dat", "r", stdin);
    iInitMap();
    //iShowMap();

    int iNum = 0;
    while (scanf("%d", &iNum) != EOF)
    {
        for (int i = 1; i < 600; i++)
        {
            for (int j = i; j < 600; j++)
            {
                if (iMap[i][j] == iNum)
                {
                    printf("%d -- %d %d -- %d\n", iNum, i, j, i + j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

// end
// ism
