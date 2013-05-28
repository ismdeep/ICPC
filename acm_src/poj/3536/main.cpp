/*
 * Project     : 3536
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Oct 16 12:30:41 2012 
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

// #define _ISM_DEBUG_

typedef unsigned long long int u_l_int;
u_l_int iSum = -1;

void init_iSum ()
{
    iSum = -1;
}

int iFactor[200];
int iTop;
void init_iTop ()
{
    iTop = -1;
}


u_l_int u_a;
u_l_int u_b;
u_l_int u_c;

void cal_out_all_iFactor (int iNum)
{
    for (int i = 1; i <= iNum; i++)
    {
	if (iNum % i == 0)
	{
	    iTop++;
	    iFactor[iTop] = i;
	}
    }
}

void cal_num (int iNum)
{
    for (int i = 0; i <= iTop; i++)
    {
	for (int j = i; j <= iTop; j++)
	{
	    for (int k = j; k <= iTop; k++)
	    {
		if (iFactor[i]*iFactor[j]*iFactor[k] == iNum)
		{
		    u_l_int iTmp = 2 * (
				      iFactor[i] * iFactor[j]
				    + iFactor[i] * iFactor[k]
				    + iFactor[j] * iFactor[k]
				       );
		    #ifdef _ISM_DEBUG_
		    	cout << iFactor[i] << " "
			     << iFactor[j] << " "
			     << iFactor[k] << " "
			     << " -- " << iTmp << endl;
		    #endif
		    if (iTmp < iSum)
		    {
			iSum = iTmp;
			u_a = iFactor[i];
			u_b = iFactor[j];
			u_c = iFactor[k];
		    }
		}
	    }
	}
    }
    cout << u_a << " " << u_b << " " << u_c << endl;
}

int main()
{
    int iNum;
    while (cin >> iNum)
    {
	init_iSum ();
	init_iTop ();
	cal_out_all_iFactor (iNum);
	cal_num (iNum);
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

