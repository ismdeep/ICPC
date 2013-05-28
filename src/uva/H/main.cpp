// Project name : H ( Triangle Wave ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 20:32:18 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int t;
	cin >> t;
	while (t--)
	{
		
		int n, m;
		cin >> n >> m;
		for (int k = 0; k < m; k++)
		{
			if (k)
			{
				cout << endl;
			}
		    for (int i = 1; i <= n; i++)
		    {
			    for (int j = 0; j < i; j++)
			    {
				    cout << i;
			    }
			    cout << endl;
		    }
		    for (int i = n - 1; i >= 1; i--)
			{
				for (int j = 0; j < i; j++)
				{
					cout << i;
				}
				cout << endl;
			}

		}
		
		if (t)
		{
		    cout << endl;
		}
	}
    return 0;
}

// end 
// ism 

