// Project name : A
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 11 09:49:53 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
	while (cin >> n >> m && n + m)
	{
		int tmp = (n * 100) % m;
		if (tmp != 0)
		{
			tmp = m - tmp;
		}

		int count = 0;
		while (tmp < 100)
		{
			if (count)
			{
				cout << " ";
			}
			count++;
			if (tmp < 10)
			{
				cout << "0";
			}
			cout << tmp;
			tmp += m;
		}

		cout << endl;
	}
    return 0;
}

// end 
// ism 

