#include <iostream>
using namespace std;

char get_upper_case (char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	return ch;
}

int main ()
{
	bool flag = true;
	char ch;
	while (cin.get(ch))
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ('\'' == ch))
		{
			if (flag)
			{
				cout << get_upper_case(ch);
			}
			else
			{
				cout << ch;
			}
			flag = false;
		}
		else
		{
			cout << ch;
			flag = true;
		}
	}
	return 0;
}