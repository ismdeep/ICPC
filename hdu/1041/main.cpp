// Project name : 1041 ( Computer Transformation ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 16:58:44 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#define LENGTH 110
#define MAXN 1010

class  Number
{
public:
     Number();
    ~Number();
    void iAdd();
    void iSub();
    void iMulTwoBy(Number iNum);
    void iShowValue();
    /* data */
    int* a;
};

Number* iMap;

/*************************************************************************************/
/* procedure */
Number::Number()
{
    a = new int[LENGTH];
    for (int i = 0; i < LENGTH; i++)
    {
        a[i] = 0;
    }
    //cout << "New Done!" << endl;
}

Number::~Number()
{
    delete[] a;
}

void Number::iAdd()
{
    a[0]++;
    int iCurrent = 0;
    while (a[iCurrent] >= 10)
    {
        a[iCurrent+1] += (a[iCurrent] / 10);
        a[iCurrent]   %= 10;
        iCurrent++;
    }
}
void Number::iSub()
{
    a[0]--;
    int iCurrent = 0;
    while (a[iCurrent] < 0)
    {
        a[iCurrent+1]--;
        a[iCurrent] += 10;
        iCurrent++;
    }
}

void Number::iMulTwoBy(Number iNum)
{
    for (int i = 0; i < LENGTH; i++)
    {
        a[i] = iNum.a[i] * 2;
    }

    for (int i = 0; i < LENGTH - 1; i++)
    {
        a[i+1] += (a[i] / 10);
        a[i]   %= 10;
    }
}

void Number::iShowValue()
{
    int iTop = LENGTH - 1;
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

void iMakeMap()
{
    iMap = new Number[MAXN];
    iMap[1].a[0] = 0;
    iMap[2].a[0] = 1;
    iMap[3].a[0] = 1;
    for (int i = 4; i < MAXN; i++)
    {
        iMap[i].iMulTwoBy(iMap[i-1]);
        if (i % 2 == 1)
        {
            //--
            iMap[i].iSub();
        }
        else
        {
            //++
            iMap[i].iAdd();
        }
    }

    iMap[3].a[1] = 0;
    iMap[3].a[0] = 1;
}

void iShowMap()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 20; j >= 0; j--)
        {
            cout << iMap[i].a[j] << " ";
        }
        cout << endl;
    }
}
/*************************************************************************************/
/* main */
int main()
{
    iMakeMap();
    //iShowMap();
    int iIndex;
    while (cin >> iIndex)
    {
        iMap[iIndex].iShowValue();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

