// Project name : A ( A - Integer Inquiry ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Thu Aug  9 14:28:43 2012


#include <iostream>
#include <stdio.h>
#include <string>
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
    int* a;
    Number();
    ~Number();
    void iAdd(string iNum);
    void iShowNum();
};

/*************************************************************************************/
/* procedure */
Number::Number()
{
    a = new int[MAXN];
    for (int i = 0; i < MAXN; i++)
    {
        a[i] = 0;
    }
}

Number::~Number()
{
    delete[] a;
}

void Number::iAdd(string iNum)
{
    int iTop = iNum.length() - 1;
    for (int i = 0; i <= iTop; i++)
    {
        a[iTop-i] += (iNum[i] - '0');
    }

    for (int i = 0; i < MAXN - 1; i++)
    {
        a[i+1] += a[i] / 10;
        a[i]   %= 10;
    }
}

void Number::iShowNum()
{
    int iTop = MAXN - 1;
    while (a[iTop] == 0)
    {
        iTop--;
    }
    for (int i = iTop; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
}

/*************************************************************************************/
/* main */
int main()
{
    Number num;
    string iNum;
    while (cin >> iNum && iNum[0] != '0')
    {
        num.iAdd(iNum);
    }
    num.iShowNum();
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

