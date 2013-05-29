// Project name : Defalut
// File name    : main.cpp
// Author       : iCoding
// Date & Time  :
// Email        : honi.linux@gmail.com

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

namespace ismdebug
{
    using namespace std;
    ifstream cin("in.dat", ios::in);
};


//using ismdebug::cin;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*****************************************************************************/
/* data */

#define MAXN 2000

int a[MAXN];
int b[MAXN];
int sum[MAXN];
string sa,sb;

/*****************************************************************************/
/* procedure */
void iInit()
{
    for (int i = 0; i < MAXN; i++)
    {
        a[i]   = 0;
        b[i]   = 0;
        sum[i] = 0;
    }
}

void iSaToArrayA()
{
    for (int i = 0; i < (int)sa.length(); i++)
    {
        a[sa.length() - i - 1] = (sa[i] - '0');
    }
}

void iSbToArrayB()
{
    for (int i = 0; i < (int)sb.length(); i++)
    {
        b[sb.length() - i - 1] = (sb[i] - '0');
    }
}

void iAdd()
{
    for (int i = 0; i < MAXN; i++)
    {
        sum[i] = a[i] + b[i];
    }
}

void iManage()
{
    for (int i = 0; i < MAXN - 1; i++)
    {
        sum[i+1] += (sum[i] / 10);
        sum[i]   %= 10;
    }
}

void iShow()
{
    int iTop =  MAXN - 1;
    while (sum[iTop] == 0)
    {
        iTop--;
    }

    for (int i = iTop; i >= 0; i--)
    {
        cout << sum[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    int iCaseCount;
    for (iCaseCount = 1; iCaseCount <= t; iCaseCount++)
    {
        if (iCaseCount != 1)
        {
            cout << endl;
        }

        cout << "Case " << iCaseCount << ":" << endl;
        cin >> sa >> sb;
        cout << sa << " + " << sb << " = ";
        iInit();
        iSaToArrayA();
        iSbToArrayB();

        /* add them */
        iAdd();
        iManage();
        iShow();
    }


    return 0;
}

// end
// iCoding@CodeLab


