/*
 * Project     : 1427
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sun Oct 14 21:12:59 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;

bool iFlag = false;

void init_flag ()
{
    iFlag = false;
}

void iTry (int iArr[], int n)
{
    if (n == 1)
    {
	if (24 == iArr[0])
        {
	    iFlag = true;
	}
    }
    else
    {
	for (int i = 0; i <= n - 2; i++)
	{
	    for (int j = i + 1; j < n; j++)
	    {
		int iIntLeft  = iArr[i];
		int iIntRight = iArr[j];
		int iIntTmp;
		/*--------------------------------------------------------------------------------*/
		//  iIntLeft + iIntRight
		iIntTmp = iIntLeft + iIntRight;
		iArr[i] = iIntTmp;
		iArr[j] = iArr[n-1];
		if (!iFlag)
		{
		    iTry (iArr, n - 1);
		}
		iArr[i] = iIntLeft;
		iArr[j] = iIntRight;
		/*--------------------------------------------------------------------------------*/
		// iIntLeft - iIntRight
		iIntTmp = iIntLeft - iIntRight;
		iArr[i] = iIntTmp;
		iArr[j] = iArr[n-1];
		if (iIntTmp > 0 && !iFlag)
		{
		    iTry (iArr, n - 1);
		}
		iArr[i] = iIntLeft;
		iArr[j] = iIntRight;
		/*--------------------------------------------------------------------------------*/
		// iIntRight - iIntLeft
		iIntTmp = iIntRight - iIntLeft;
		iArr[i] = iIntTmp;
		iArr[j] = iArr[n-1];
		if (iIntTmp > 0 && !iFlag)
		{
		    iTry (iArr, n - 1);
		}
		iArr[i] = iIntLeft;
		iArr[j] = iIntRight;
		/*--------------------------------------------------------------------------------*/
		// iIntLeft  * iIntRight
		iIntTmp = iIntLeft * iIntRight;
		iArr[i] = iIntTmp;
		iArr[j] = iArr[n-1];
		if (!iFlag)
		{
		    iTry (iArr, n - 1);
		}
		iArr[i] = iIntLeft;
		iArr[j] = iIntRight;
		/*--------------------------------------------------------------------------------*/
		// iIntLeft  / iIntRight
		if (iIntRight != 0 && iIntLeft % iIntRight == 0)
		{
		    iIntTmp = iIntLeft / iIntRight;
		    iArr[i] = iIntTmp;
		    iArr[j] = iArr[n-1];
		    if (!iFlag)
		    {
			iTry (iArr, n - 1);
		    }
		    iArr[i] = iIntLeft;
		    iArr[j] = iIntRight;
		}
		/*--------------------------------------------------------------------------------*/
		// iIntRight / iIntLeft
		if (iIntLeft != 0 && iIntRight % iIntLeft == 0)
		{
		    iIntTmp = iIntRight / iIntLeft;
		    iArr[i] = iIntTmp;
		    iArr[j] = iArr[n-1];
		    if (!iFlag)
		    {
			iTry (iArr, n - 1);
		    }
		    iArr[i] = iIntLeft;
		    iArr[j] = iIntRight;
		}
	    }
	}
    }
}

int translate_string_to_int (string iStr)
{
    int iInt;
    if ("A" == iStr)
    {
	iInt = 1;
    }
    else if ("2" == iStr)
    {
	iInt = 2;
    }
    else if ("3" == iStr)
    {
	iInt = 3;
    }
    else if ("4" == iStr)
    {
	iInt = 4;
    }
    else if ("5" == iStr)
    {
	iInt = 5;
    }
    else if ("6" == iStr)
    {
	iInt = 6;
    }
    else if ("7" == iStr)
    {
	iInt = 7;
    }
    else if ("8" == iStr)
    {
	iInt = 8;
    }
    else if ("9" == iStr)
    {
	iInt = 9;
    }
    else if ("10" == iStr)
    {
	iInt = 10;
    }
    else if ("J" == iStr)
    {
	iInt = 11;
    }
    else if ("Q" == iStr)
    {
	iInt = 12;
    }
    else if ("K" == iStr)
    {
	iInt = 13;
    }
    //
    return iInt;
}

int main()
{
    string iStrArr[4];
    while (cin >> iStrArr[0] >> iStrArr[1] >> iStrArr[2] >> iStrArr[3])
    {
	init_flag ();
	int iIntArr[4];
	// translate_string_to_int
	for (int i = 0; i < 4; i++)
	{
	    iIntArr[i] = translate_string_to_int (iStrArr[i]);
	}
	// iTry to do the force process
	iTry (iIntArr, 4);
	// judge and output result
	if (iFlag)
	{
	    cout << "Yes" << endl;
	}
	else
	{
	    cout << "No"  << endl;
	}
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

