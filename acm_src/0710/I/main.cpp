// Project name : I
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 14:50:07 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
	while (cin >> s && s != "0")
	{
		int n = 0;
		int top = 0;
		while (s[top] != '\0')
		{
			n += (s[top] - '0');
			top++;
		}

		int sum = n;
		while (sum >= 10)
		{
			sum = (sum / 10) + sum % 10;
		}
		cout << sum << endl;
	}
    return 0;
}

// end 
// ism 

