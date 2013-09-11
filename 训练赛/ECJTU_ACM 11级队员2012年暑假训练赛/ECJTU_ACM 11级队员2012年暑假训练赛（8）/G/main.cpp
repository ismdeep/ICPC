// Project name : G
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 15:24:28 2012


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


/*************************************************************************************/
/* main */
int main()
{
    string s;
    while (cin >> s)
    {
        int count = 0;
        int top = s.length() - 1;
        for (int i = 0; i <= top; i++)
        {
            if (s[i] == '4' || s[i] == '7')
            {
                count++;
            }
        }

        //cout << count << endl;

        bool yes = true;
        if (count == 0)
        {
            yes = false;
        }
        while (yes == true && count)
        {
            if (count % 10 == 4 || count % 10 == 7)
            {
                count /= 10;
            }
            else
            {
                yes = false;
            }
        }

        if (yes)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO"  << endl;
        }
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

