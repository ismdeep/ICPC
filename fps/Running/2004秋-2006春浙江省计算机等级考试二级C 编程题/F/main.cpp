/*
 * Project     : F
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Fri Sep 28 14:58:54 2012 
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

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp;
	while (cin >> tmp && tmp != 0)
	{
		if (tmp >= 85)
		{
			a++;
		}
		else if (tmp >= 60)
		{
			b++;
		}
		else
		{
			c++;
		}
	}
	cout << ">=85:"  << a << endl
		 << "60-84:" << b << endl
		 << "<60:"   << c << endl;
	return 0;
}

// end 
// iCoding@CodeLab
//

