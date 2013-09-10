#include <iostream>
using namespace std;

int main ()
{
	char ch;
	bool double_quote_flag = false;
	bool single_quote_flag = false;

	while (cin.get(ch))
	{
		if (ch == '\"')
		{
			if (double_quote_flag)
			{
				//cout << ch;
				cout << "\'\'";
			}
			else
			{
				cout << "``";
			}
			double_quote_flag = 1 - double_quote_flag;
		}
		else if (ch == '\'')
		{
			if (single_quote_flag)
			{
				cout << ch;
			}
			else
			{
				cout << "`";
			}
			single_quote_flag = 1 - single_quote_flag;
		}
		else
		{
			cout << ch;
		}
	}

	return 0;
}


