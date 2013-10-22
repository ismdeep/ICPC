// Project name : 1020 ( A Childhood Game ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Sat Aug 11 13:45:21 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
const string Alice = "Alice";
const string Bob   = "Bob"  ;

/*************************************************************************************/
/* procedure */


/*************************************************************************************/
/* main */
int main()
{
    int iT;
    cin >> iT;
    for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        int iNum;
        string iStarter;
        printf("Case %d: ", iCaseCount);
        cin >> iNum >> iStarter;
        if (iStarter == Bob)
        {
            /* If Bob starts first, then the player who takes the last marble wins the game. */
            if (iNum % 3 == 0)
            {
                cout << Alice << endl;
            }
            else
            {
                cout << Bob << endl;
            }
        }
        else
        {
            /* If Alice starts first, then the player who takes the last marble looses the game. */
            if ((iNum-1) % 3 == 0)
            {
                cout << Bob << endl;
            }
            else
            {
                cout << Alice << endl;
            }
        }
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

