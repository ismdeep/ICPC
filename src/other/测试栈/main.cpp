// Project name : 测试栈
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 19:56:20 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */


/*************************************************************************************/
/* procedure */

void iTry(int x, int y, int value)
{
    value = x * y;
    cout << x << " " << value << endl;

    if (x == 1000000)
    {
        return;
    }
    else
    {
        iTry(x + 1, y + 1, value);
    }
}

/*************************************************************************************/
/* main */
int main()
{
    iTry(1, 1, 1);
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

