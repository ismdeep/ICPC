// Project name : C ( The Decoder ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 19:28:03 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    char ch;
	while (cin.get(ch))
	{
		ch = ch - ('J' - 'C');
		cout << ch;
		while (cin.get(ch) && ch != '\n')
		{
			ch = ch - ('J' - 'C');
			cout << ch;
		}
		cout << endl;
	}
    return 0;
}

// end 
// ism 

