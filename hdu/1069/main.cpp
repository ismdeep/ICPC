// Project name : 1069 ( Monkey and Banana ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 14:39:00 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#define MAXN 40

class Block
{
public:
    int x;
    int y;
    int height;
    /*x <= y*/
    void manage();
    void setValue(int x, int y, int height);
    void showMap();
};

int n;
Block iMap[MAXN*3];

int iSum[MAXN*3];

/*************************************************************************************/
/* procedure */
void Block::manage()
{
    if (x > y)
    {
        int tmp;
        tmp = x;
        x   = y;
        y   = tmp;
    }
}

void Block::setValue(int x, int y, int height)
{
    this -> x      = x;
    this -> y      = y;
    this -> height = height;
}

void Block::showMap()
{
    cout << x << " " << y << " - " << height << endl;
}

bool cmp(Block a, Block b)
{
    if ((a.x >= b.x && a.y >= b.y) || ((a.x * a.y) >= (b.x * b.y)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void iInit()
{
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        iMap[i*3]  .setValue(a, b, c);
        iMap[i*3+1].setValue(b, c, a);
        iMap[i*3+2].setValue(c, a, b);
        iMap[i*3]  .manage();
        iMap[i*3+1].manage();
        iMap[i*3+2].manage();
    }
    sort(iMap, iMap + 3 * n, cmp);
}

void debug()
{
    for (int i = 0; i < n * 3; i++)
    {
        iMap[i].showMap();
    }
}

bool iCanPut(Block bottom, Block up)
{
    if (bottom.x > up.x && bottom.y > up.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void iDynamicProgramming()
{
    for (int i = 0; i < 3 * n; i++)
    {
        int iMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (iCanPut(iMap[j], iMap[i]) && iSum[j] > iMax)
            {
                iMax = iSum[j];
            }
        }
        iSum[i] = iMap[i].height + iMax;
    }
}

void iShowResult()
{
    int iMax = 0;
    for (int i = 0; i < 3 * n; i++)
    {
        if (iSum[i] > iMax)
        {
            iMax = iSum[i];
        }
    }
    cout << iMax << endl;
}

/*************************************************************************************/
/* main */
int main()
{
    int iCaseCount = 0;
    while (cin >> n && n)
    {
        iCaseCount++;
        cout << "Case " << iCaseCount << ": maximum height = ";
        iInit();
        //debug();
        iDynamicProgramming();
        iShowResult();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

