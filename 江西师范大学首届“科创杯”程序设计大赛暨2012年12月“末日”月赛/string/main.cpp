#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

int iCount[26];
string str;

int main ()
{
	while (cin >> str && "END" != str)
	{
		char ch;
		memset (iCount, 0, sizeof(iCount));
		for (int i = 0; i < str.length(); i++)
		{
			ch = str[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch -= 32;
			}
			if (ch >= 'A' && ch <= 'Z')
			{
				iCount[ch - 'A']++;
			}
		}
		for (int i = 0; i < 25; i++)
		{
			if (iCount[i] != 0)
			{
				char ch;
				ch = 'A' + i;
				cout << ch << " " << iCount[i] << " " << endl;
			}
		}
		cout << "OVER" << endl;
	}
	return 0;
}
