// Project name : H ( Petya and Strings ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 13:14:48 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
string sa, sb;

/*************************************************************************************/
/* procedure */

int iCalForResult()
{
    int iTop = sa.length() - 1;
    for (int i = 0; i <= iTop; i++)
    {
        if (sa[i] >= 'A' && sa[i] <= 'Z')
        {
            sa[i] += 32;
        }
        if (sb[i] >= 'A' && sb[i] <= 'Z')
        {
            sb[i] += 32;
        }
    }

    int res = 0;
    for (int i = 0; res == 0 && i <= iTop; i++)
    {
        if (sa[i] > sb[i])
        {
            res = 1;
        }
        else if (sa[i] < sb[i])
        {
            res = -1;
        }
    }
    return res;
}
/*************************************************************************************/
/* main */
int main()
{
    while (cin >> sa >>sb)
    {
        cout << iCalForResult() << endl;
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

