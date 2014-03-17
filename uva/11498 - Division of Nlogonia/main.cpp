/* 
 * Project Name : 11498
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Wed Dec 18 13:52:04 2013 
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

//#define _ISM_DEBUG_ 

string _map_[3][3] = {
	{"SO"    , "divisa", "SE"    },

	{"divisa", "divisa", "divisa"},
	
	{"NO"    , "divisa", "NE"    }
};


int main () 
{
	int k;
	while (cin >> k, k)
	{
		int cx, cy;
		cin >> cx >> cy;
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			int i,j;
			i = 0;
			j = 0;
			if (x < cx)
			{
				j = -1;
			}
			if (x > cx)
			{
				j = 1;
			}
			if (y < cy)
			{
				i = -1;
			}
			if (y > cy)
			{
				i = 1;
			}
			i++;
			j++;
#ifdef _ISM_DEBUG_
			printf ("%d,%d - %d,%d : ", cx,cy,x,y);
#endif
			cout << _map_[i][j] << endl;
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

