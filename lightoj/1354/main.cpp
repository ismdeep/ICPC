// Project name : 1354 ( IP Checking ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 10:01:30 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

int a, b, c, d;
bool iFlag;
string ip;
int tmp;
/*************************************************************************************/
/* procedure */

void iInit()
{
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    //printf("%d %d %d %d \n", a, b, c, d);
    cin >> ip;
    iFlag = true;
}

void iShow(int a, int b)
{
    cout << a << " " << b << endl;
}

bool iIsEqual()
{
    tmp = 0;
    int iIndex = 0;
    while (ip[iIndex] != '.')
    {
        tmp *= 2;
        tmp += (ip[iIndex] - '0');
        iIndex++;
    }
    if (tmp != a)
    {
        iFlag = false;
    }

    tmp = 0;
    iIndex++;
    while (ip[iIndex] != '.')
    {
        tmp *= 2;
        tmp += (ip[iIndex] - '0');
        iIndex++;
    }
    //iShow(tmp,b);
    if (tmp != b)
    {
        iFlag = false;
    }

    tmp = 0;
    iIndex++;
    while (ip[iIndex] != '.')
    {
        tmp *= 2;
        tmp += (ip[iIndex] - '0');
        iIndex++;
    }
    if (tmp != c)
    {
        iFlag = false;
    }


    tmp = 0;
    iIndex++;
    while (ip[iIndex] != '\0')
    {
        tmp *= 2;
        tmp += (ip[iIndex] - '0');
        iIndex++;
    }
    if (tmp != d)
    {
        iFlag = false;
    }


    return iFlag;
}

/*************************************************************************************/
/* main */
int main()
{
    int iT;
    scanf("%d", &iT);
    for (int  iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        printf("Case %d: ", iCaseCount);

        iInit();

        if (iIsEqual())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

