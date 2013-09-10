// Project name : 1000 ( Greetings from Lightoj ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 19:03:10 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
int a, b;

/*************************************************************************************/
/* procedure */

void iCal(int iCase)
{
    cout << "Case " << iCase << ": " ;
    cin >> a >> b;
    cout << a + b << endl;
}

/*************************************************************************************/
/* main */
int main()
{
    int iT;
    cin >> iT;
    for (int iCase = 1; iCase <= iT; iCase++)
    {
        iCal(iCase);
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

