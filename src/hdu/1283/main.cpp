// Project name : 1283 ( 最简单的计算机 ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 17:39:35 2012


#include <iostream>
using namespace std;

int main()
{
    int m1, m2;
	while (cin >> m1 >> m2)
	{
	    string s;
		cin >> s;
		int current = 0;
		int r1 = 0, r2 = 0, r3 = 0;
		while (s[current] != '\0')
		{
		    if (s[current] == 'A')
			{
			    r1 = m1;
			}
			if (s[current] == 'B')
			{
			    r2 = m2;
			}
			if (s[current] == 'C')
			{
			    m1 = r3;
			}
			if (s[current] == 'D')
			{
			    m2 = r3;
			}
			if (s[current] == 'E')
			{
			    r3 = r1 + r2;
			}
			if (s[current] == 'F')
			{
			    r3 = r1 - r2;
			}
			current++;
		}
		cout << m1 << "," << m2 << endl;
	}
    return 0;
}

// end 
// ism 

