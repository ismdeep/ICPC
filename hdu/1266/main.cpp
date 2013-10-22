// Project name : 1266
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 17:12:48 2012


#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
	cin >> n;
	while (n--)
	{
	    char s[1000];
		cin >> s;

		if (s[0] == '-')
		{
		    cout << "-";
		}

		int top = 0;
		while (s[top] != '\0')
		{
		    top++;
		}
		top--;

		int current = top;
		while (s[current] == '0' && current >= 0)
		{
		    current--;
		}

		while (s[current] >= '0' && s[current] <= '9')
		{
		    cout << s[current];
			current--;
		}

		while (s[top] == '0' && top >= 0)
		{
		    cout << "0";
			top--;
		}

		cout << endl;

	}
    return 0;
}

// end 
// ism 

