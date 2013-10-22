// Project name : 1219 ( AC Me ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 19:45:31 2012


#include <iostream>
using namespace std;

int main()
{
    int count[26];
	char ch;
	while (cin.get(ch))
	{
	    // init for count[26]
		for (int i = 0; i < 26; i++)
		{
		    count[i] = 0;
		}
		count[ch - 'a']++;

		while (cin.get(ch) && ch != '\n')
		{
		    // cout << ch << endl;
			if (ch >= 'a' && ch <= 'z')
			{
			    count[ch - 'a']++;
			}
		}

		// output 
		for (int i = 0; i < 26; i++)
		{
		    cout << (char) (i + 'a') << ":" << count[i] << endl;
		}
		cout << endl;
	}
    return 0;
}

// end 
// ism 

