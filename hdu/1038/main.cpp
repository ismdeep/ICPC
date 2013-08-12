// Project name : 1038 ( Bikers Trip Odometer ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 16:42:26 2012


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
    const double pi = 3.141592653;
    double d;
    int r;
    double t;
    int iCaseCount = 0;
    while (cin >> d >> r >> t && r)
    {
        iCaseCount++;
        double res1 = pi * d * r / (12 * 5280);
        double res2 = res1 / t * 3600;
        //cout << "Trip #" << iCaseCount << ": " << res1 << " " << res2 << endl;
        printf("Trip #%d: %.2f %.2f\n", iCaseCount, res1, res2);
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

