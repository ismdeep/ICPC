// Project name : Defalut
// File name    : main.cpp
// Author       : iCoding
// Date & Time  :
// Email        : honi.linux@gmail.com

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int iStart, iEnd;

int iStartRow;
int iStartRowID;
int iEndRow;
int iEndRowID;

int iCalRow(int iID)
{

}

int iCalRowID(int iID)
{

}

int main()
{
    freopen("in.dat", "r", stdin);

    while (scnaf("%d%d", &iStart, &iEnd) != EOF)
    {
        iStartRow   = iCalRow(iStart);
        iStartRowID = iCalRowID(iStart);
        iEndRow     = iCalRow(iEnd);
        iEndRowID   = iCalRowID(iEnd);


    }

    return 0;
}

// end
// iCoding@CodeLab


