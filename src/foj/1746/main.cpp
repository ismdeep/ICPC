// Project name : 1746 ( A Water Problem ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 14:24:24 2012


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
	while (cin >> s)
	{
	    for (int i = 0; i < 23; i++)
		{
		    cin >> s;
		}

		if (s == ".....#..........#.......")
		{
		    cout << "Black King" << endl;
		}
		else
		{
		    cout << "Red General" << endl;
		}
	}
    return 0;
}

// end 
// ism 

