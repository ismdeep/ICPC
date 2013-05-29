// Project name : A
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 17:36:39 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    long long int x, y;
	while (cin >> x >> y)
	{
		if (x > y)
		{
		    cout << x - y << endl;
		}
		else
		{
		    cout << y - x << endl;
		}
	}
    return 0;
}

// end 
// ism 

