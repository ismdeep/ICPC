// Project name : G
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 14:15:29 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
	while (cin >> s)
	{
	    string num[10];
		for (int i = 0; i < 10; i++)
		{
			cin >> num[i];
		}

		char str_tmp[20];
		for (int time = 0; time < 8; time++)
		{
			// init for str_tmp
			for (int i = 0; i < 20; i++)
			{
				str_tmp[i] = '\0';
			}

			for (int i = 0; i < 10; i++)
			{
				str_tmp[i] = s[time * 10 + i];
			}

			string s_tmp = str_tmp;

			bool found = false;
			for (int i = 0; !found && i < 10; i++)
			{
				if (s_tmp == num[i])
				{
					cout << i;
					found = true;
				}
			}
		}
		cout << endl;
	}
    return 0;
}

// end 
// ism 

