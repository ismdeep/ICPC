// Project name : 1012 ( 1012 Guilty Prince ) 
// File name    : main.cpp
// Author       : iCoding
// E-mail       : honi.linux@gmail.com
// Date & Time  : Wed Aug  8 19:11:24 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

/*************************************************************************************/
/* data */
#ifndef MAXN
#define MAXN 30
#endif

const char CH_EMPTY = '.';
const char CH_START = '@';
const char CH_BLOCK = '#';

int n, m;

char iMap[MAXN][MAXN];

int iAnswer;

int dir_x[4] = {0 , 0, -1, 1};
int dir_y[4] = {-1, 1,  0, 0};

int start_x;
int start_y;
/*************************************************************************************/
/* procedure */
void debug()
{
    cout << "--debug msg--" << endl;
}
void iInit()
{
    /*set all memory of iMap to CH_BLOCK*/
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            iMap[i][j] = CH_BLOCK;
        }
    }

    /*init for iAnswer*/
    iAnswer = 0;

    /*init for iMap*/
    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        //cout << line << endl;
        for (int j = 1; j <= m; j++)
        {
            if      (line[j-1] == CH_EMPTY)
            {
                iMap[i][j] = CH_EMPTY;
            }
            else if (line[j-1] == CH_BLOCK)
            {
                iMap[i][j] = CH_BLOCK;
            }
            else if (line[j-1] == CH_START)
            {
                iMap[i][j] = CH_EMPTY;
                start_x = i;
                start_y = j;
            }
        }
    }
}

bool iCanGo(int x, int y)
{
    if (iMap[x][y] == CH_BLOCK)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void iDFS(int x, int y)
{
    //debug();
    //cout << "--" << x <<  " " << y << endl;
    /*iMap[x][y] = CH_BLOCK;
    iAnswer++;
    for (int iDirCase = 0; iDirCase < 4; iDirCase++)
    {
        if (iCanGo(x + dir_x[iDirCase] , y + dir_y[iDirCase]))
        {
            iDFS(x + dir_x[iDirCase] , y + dir_y[iDirCase]);
        }
    }*/

    bool iFlagGo[4] = {false, false, false, false};
    for (int iDirCase = 0; iDirCase < 4; iDirCase++)
    {
        if (iCanGo(x + dir_x[iDirCase] , y + dir_y[iDirCase]))
        {
            iFlagGo[iDirCase] = true;
            iMap[x + dir_x[iDirCase]][y + dir_y[iDirCase]] = CH_BLOCK;
            iAnswer++;
        }
    }

    for (int iDirCase = 0; iDirCase < 4; iDirCase++)
    {
        if (iFlagGo[iDirCase])
        {
            iDFS(x + dir_x[iDirCase] , y + dir_y[iDirCase]);
        }
    }
}


/*************************************************************************************/
/* main */
int main()
{
    int iT;
    cin >> iT;
    for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
    {
        cout << "Case " << iCaseCount << ": ";
        cin >> m >> n;
        iInit();
        iMap[start_x][start_y] = CH_BLOCK;
        iAnswer = 1;
        iDFS(start_x, start_y);
        cout << iAnswer << endl;
    }
    return 0;
}

// end 
// Code by Sublime text 2
// iCoding@CodeLab 

