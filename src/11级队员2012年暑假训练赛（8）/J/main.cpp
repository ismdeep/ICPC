// Project name : J ( Word Problem ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 12:32:18 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */

#ifndef MAXN
#define MAXN 100
#endif

string iList[MAXN];
int iTop;

string s;
int sTop;

char s_tmp[MAXN];
int s_tmp_top;
/*************************************************************************************/
/* procedure */

void iShowList()
{
    for (int i = 0; i <= iTop; i++)
    {
        cout << iList[i] << endl;
    }
}

void iInit()
{
    iTop = -1;

    sTop = s.length() - 1;
    if ((s[sTop] >= 'a' && s[sTop] <= 'z') || (s[sTop] >= 'A' && s[sTop] <= 'Z'))
    {
        sTop++;
        s[sTop] = '_';
    }
}

void iInitTmp()
{
    for (int i = 0; i < MAXN; i++)
    {
        s_tmp[i] = '\0';
    }
    s_tmp_top = -1;
}

void iCal()
{
    iInitTmp();
    bool hasword = false;

    for (int i = 0; i <= sTop; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s_tmp_top++;
            s_tmp[s_tmp_top] = s[i];
            hasword = true;
            //cout << s[i] << endl;
        }
        else
        {
            if (hasword)
            {
                // go search
                string sss = s_tmp;
                bool iFound = false;
                for (int i = 0; !iFound && i <= iTop; i++)
                {
                    if (iList[i] == sss)
                    {
                        iFound = true;
                    }
                }
                if (!iFound)
                {
                    iTop++;
                    iList[iTop] = sss;
                }
                iInitTmp();
                hasword = false;
            }
            
        }
    }
}

/*************************************************************************************/
/* main */
int main()
{
    while (cin >> s)
    {
        iInit();
        iCal();
        iShowList();
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

