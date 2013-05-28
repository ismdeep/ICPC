// Project name : 2101 ( A + B Problem Too ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 15:54:32 2012


#include <iostream>
using namespace std;

int main()
{
    int a, b;
	while (cin >> a >> b)
	{
		if ((a + b) % 86 == 0)
		{
		    cout << "yes" << endl;
		}
		else
		{
		    cout << "no" << endl;
		}
	}
    return 0;
}

// end 
// ism 

