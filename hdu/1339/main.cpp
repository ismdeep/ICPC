// Project name : 1339 ( A Simple Task ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 19:35:53 2012


#include <iostream>
using namespace std;

int main()
{
    int t;
	cin >> t;
	while (t--)
	{
	    int num;
		cin >> num;
		int p = 0;
		while (num % 2 == 0)
		{
		    num /= 2;
			p++;
		}
		cout << num << " " << p << endl;
	}
    return 0;
}

// end 
// ism 

