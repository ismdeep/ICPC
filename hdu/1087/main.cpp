// Project name : 1087 ( Super Jumping! Jumping! Jumping! ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 11:19:00 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*******************************************************************************/
/*data*/
#define MAXN 2000

int iMap[MAXN];
int iSum[MAXN];

int n;

/*******************************************************************************/
/*procedure*/
void iInit()
{
    for (int i = 0; i < n; i++)
    {
        cin >> iMap[i];
    }
}

void iDynamicProgramming()
{
    for (int i = 0; i < n; i++)
    {
        int iMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (iMap[j] < iMap[i] && iSum[j] > iMax)
            {
                iMax = iSum[j];
            }
        }
        iSum[i] = iMap[i] + iMax;
    }
}

void iShowResult()
{
    int iMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (iSum[i] > iMax)
        {
            iMax = iSum[i];
        }
    }
    cout << iMax << endl;
}
/*******************************************************************************/
/*main*/
int main()
{
    while (cin >> n && n > 0)
    {
        iInit();
        iDynamicProgramming();
        iShowResult();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

