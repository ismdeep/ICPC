// Project name : 1004 ( Monkey Banana Problem ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Thu Aug  9 12:13:15 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#ifndef MAXN
#define MAXN 110
#endif
int iMap[MAXN*2][MAXN];

const int BLOCK = -1;

int n;

/*************************************************************************************/
/* procedure */
bool iCanGo(int x, int y)
{
    if (iMap[x][y] == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void iInit()
{
    for (int i = 0; i < MAXN * 2; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            iMap[i][j] = BLOCK;
        }
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &iMap[i][j]);
        }
    }
    for (int i = n + 1; i < 2 * n; i++)
    {
        for (int j = 1; j <= (2 * n - i); j++)
        {
            scanf("%d", &iMap[i][j]);
        }
    }
}

void iDynamicProgramming()
{
    for (int i = (n * 2 - 2); i >= n; i--)
    {
        for (int j = 1; j <= (2 * n - i); j++)
        {
            int iMax = -1;
            if (iCanGo(i+1,j-1) && iMap[i+1][j-1] > iMax)
            {
                iMax = iMap[i+1][j-1];
            }

            if (iCanGo(i+1,j) && iMap[i+1][j] > iMax)
            {
                iMax = iMap[i+1][j];
            }

            iMap[i][j] = iMax + iMap[i][j];
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (iMap[i+1][j] > iMap[i+1][j+1])
            {
                iMap[i][j] += iMap[i+1][j];
            }
            else
            {
                iMap[i][j] += iMap[i+1][j+1];
            }
        }
    }
}

void iShowMap()
{
    for (int i = 0; i <= n * 2; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d ", iMap[i][j]);
        }
        printf("\n");
    }
}

void iShowResult()
{
    printf("%d\n", iMap[1][1]);
}

/*************************************************************************************/
/* main */
int main()
{
    int iT;
    scanf("%d", &iT);
    for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        printf("Case %d: ", iCaseCount);
        iInit();
        iDynamicProgramming();
        //iShowMap();
        iShowResult();

    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

