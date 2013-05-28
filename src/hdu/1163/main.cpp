// Project name : 1163 ( Eddy's digital Roots ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 20:59:43 2012


#include <iostream>
using namespace std;

int main()
{
    int n;
	while (cin >> n && n)
	{
	    int sum = 1;
		for (int i = 0; i < n; i++)
		{
		    sum = sum * n % 9;
		}

		if (sum == 0)
		{
		    cout << "9" << endl;
		}
		else
		{
		    cout << sum << endl;
		}
	}
    return 0;
}

// end 
// ism 

