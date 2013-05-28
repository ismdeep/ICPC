/* 
 * Project Name : E
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Tue Oct 30 15:53:10 2012 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

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
			int tmp;
			cin >> iStrLeft;
			if (iStrLeft.length() < 25)
			{
				cin >> iStrRight;
				tmp = 25 - iStrLeft.length () - iStrRight.length ();
				for (int i = 0; i < iStrLeft.length(); i++)
				{
					if ('X' != iStrLeft[i])
					{
						tmp++;
					}
				}
				for (int i = 0; i < iStrRight.length(); i++)
				{
					if ('X' != iStrRight[i])
					{
						tmp++;
					}
				}
			}
			else
			{
				tmp = 25 - iStrLeft.length ();
				for (int i = 0; i < iStrLeft.length(); i++)
				{
					if ('X' != iStrLeft[i])
					{
						tmp++;
					}
				}
			}
			iBlankSum += tmp;
			if (tmp < iMinLength)
			{
				iMinLength = tmp;
			}
		}
		iBlankSum = iBlankSum - iCountLine * iMinLength;
		cout << iBlankSum << endl;
	}
	return 0;
}

// end 
// namespace
// CodeLab
// 

