// Project name : B ( B - Product ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Thu Aug  9 14:39:57 2012


#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

#ifndef MAXN
#define MAXN 1000
#endif

class Number
{
public:
    int a[MAXN];
    int iTop;
    Number(string iNum);
    //~Number();
    void mulWithNumber(Number iNum);
};

/*************************************************************************************/
/* procedure */

Number::Number(string iNum)
{
    //a = new int[MAXN];
    memset(a, 0, sizeof(a));
    iTop = iNum.length() - 1;
    for (int i = 0; i <= iTop; i++)
    {
        a[iTop-i] = (iNum[i] - '0');
    }
}

/*Number::~Number()
{
    delete[] a;
}*/

void Number::mulWithNumber(Number iNum)
{
    int iSum[MAXN*2];
    memset(iSum, 0, sizeof(iSum));

    for (int i = 0; i <= iTop; i++)
    {
        for (int j = 0; j <= iNum.iTop; j++)
        {
            iSum[i+j] += (a[i] * iNum.a[j]);
        }
    }

    for (int i = 0; i < MAXN * 2 - 1; i++)
    {
        iSum[i+1] += (iSum[i] / 10);
        iSum[i]   %= 10;
    }

    int top = 2 * MAXN - 1;
    while (iSum[top] == 0 && top > 0)
    {
        top--;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << iSum[i];
    }
    cout << endl;
}

/*************************************************************************************/
/* main */
int main()
{
    string iNum1, iNum2;
    while (cin >> iNum1 >> iNum2)
    {
        int flag = 0;
        if (iNum1[0] == '-')
        {
            flag++;
            char tmp[MAXN];
            for (int i = 1; i <= iNum1.length(); i++)
            {
                tmp[i-1] = iNum1[i];
            }
            iNum1 = tmp;
        }
        if (iNum2[0] == '-')
        {
            flag++;
            char tmp[MAXN];
            for (int i = 1; i <= iNum2.length(); i++)
            {
                tmp[i-1] = iNum2[i];
            }
            iNum2 = tmp;
        }
        if (flag == 1)
        {
            cout << "-";
        }
        //cout << iNum1 << " " << iNum2 << endl;
        Number num1(iNum1), num2(iNum2);
        num1.mulWithNumber(num2);
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

