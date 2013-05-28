// Project name : 1001 ( Color the ball ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Tue Aug  7 13:45:34 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100100

int iMap[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n > 0)
    {
        memset(iMap, 0, sizeof(iMap));

        for (int i = 0; i < n; i++)
        {
            int iStart, iEnd;
            scanf("%d%d", &iStart, &iEnd);
            for (int j = iStart; j <= iEnd; j++)
            {
                iMap[j]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << iMap[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

