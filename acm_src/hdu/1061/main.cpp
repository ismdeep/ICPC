// Project name : 1061 ( Rightmost Digit ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Mon Jul  9 09:32:56 2012


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
		int a = num % 10;
		num = num % 4;
		int sum = a;
		if (num == 0)
		{
		    num = 4;
		}
		for (int i = 0; i < num - 1; i++)
		{
		    sum *= a;
		}
		cout << sum % 10 << endl;
	}
    return 0;
}

// end 
// ism 

