// Project name : A
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Fri Aug 10 13:36:56 2012


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

typedef long long int longint;

longint iMin(longint a, longint b)
{
    return a > b ? b : a;
}

longint iCalCou(longint num, longint a)
{
    /*longint up[1000];
    longint down[1000];
    for (int i = 0; i < a; i++)
    {
        up[i] = num - i;
        down[i] = i + 1;
    }
    */
    longint iAnswer = 1;
    for (int i = 0; i < a; i++)
    {
        iAnswer *= (num - i);
        iAnswer /= (i + 1);
    }

    return iAnswer;
}
/*************************************************************************************/
/* main */
int main()
{
    longint n, m;
    while(cin >> n >> m && n + m)
    {
        cout << iCalCou(n + m , iMin(n,m)) << endl;
    }
    return 0;
}
// end 
// Code by Sublime text 2
// iCoding@CodeLab 

