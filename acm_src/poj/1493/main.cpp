/*
 * Project     : 1493
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Mon Oct 15 18:10:37 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
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

int main()
{
    int iCountLine;
    while (cin >> iCountLine && iCountLine)
    {
	int iMinLength = 25;
	int iBlankSum = 0;
	string iStrLeft, iStrRight;
	for (int i = 0; i < iCountLine; i++)
	{
	    cin >> iStrLeft;
	    if (iStrLeft.length() < 25)
	    {
	        cin >> iStrRight;
		int tmp = 25 - iStrLeft.length () - iStrRight.length ();
		iBlankSum += tmp;
		if (tmp < iMinLength)
		{
		    iMinLength = tmp;
		}
	    }
	    else
	    {
		iMinLength = 0;
	    }
	}
	#ifdef _ISM_DEBUG_
	    cout << iBlankSum << " " << iMinLength << endl;
	#endif
	iBlankSum = iBlankSum - iCountLine * iMinLength;
	cout << iBlankSum << endl;    
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

