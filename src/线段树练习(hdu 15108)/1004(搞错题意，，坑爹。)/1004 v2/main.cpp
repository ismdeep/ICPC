// Project name : 1004 ( Minimum Inversion Number ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 13:19:00 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#define MAXN 5050

int iNum[MAXN];
int iMap[MAXN*4];
int n;

/*************************************************************************************/
/* procedure */
void iInit()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> iNum[i];
    }
}

void iShowNumArr()
{
    for (int i = 1; i <= n; i++)
    {
        cout << iNum[i] << " ";
    }
    cout << endl;
}

int iCalTwoSection(int left_start, int left_end, int right_start, int right_end)
{
    int iTmpCount = 0;
    for (int i = left_start; i <= left_end; i++)
    {
        for (int j = right_start; j <= right_end; j++)
        {
            if (iNum[i] > iNum[j])
            {
                iTmpCount++;
            }
        }
    }
    cout << "--debug-->" << left_start << " " << left_end << " - " << right_start << " " << right_end << " - - " << iTmpCount << endl;
    return iTmpCount;
}

void iCreatMap(int iStart, int iEnd, int iID)
{
    if (iStart == iEnd)
    {
        iMap[iID] = 0;
    }
    else
    {
        int iMid = (iStart + iEnd) / 2;
        iCreatMap(iStart  , iMid, iID * 2);
        iCreatMap(iMid + 1, iEnd, iID * 2 + 1);
        int iTmpCount = 0;
        iTmpCount  = iCalTwoSection(iStart, iMid, iMid + 1, iEnd);
        iTmpCount += iMap[iID*2];
        iTmpCount += iMap[iID*2+1];
        iMap[iID] = iTmpCount;
    }
}

void iShowResult()
{
    cout << iMap[1] << endl;
}
/*************************************************************************************/
/* main */
int main()
{
    while (cin >> n)
    {
        iInit();
        iShowNumArr();
        iCreatMap(1, n, 1);
        iShowResult();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

