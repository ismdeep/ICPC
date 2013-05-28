// Project name : 1161 ( Eddy's mistakes ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 09:45:51 2012


#include <iostream>
using namespace std;

int main()
{
    char ch;
	while (cin.get(ch))
	{
	    if (ch >= 'A' && ch <= 'Z')
		{
		    ch = ch + ('a' - 'A');
		}
		cout << ch;
		while (cin.get(ch) && ch != '\n')
		{
		    if (ch >= 'A' && ch <= 'Z')
			{
			    ch = ch + ('a' - 'A');
			}
			cout << ch;
		}
		cout << endl;
	}
    return 0;
}

// end 
// ism 

