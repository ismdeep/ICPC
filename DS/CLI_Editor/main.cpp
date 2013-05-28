/*
 * Project     : CLI_Editor
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Sep 25 18:46:29 2012 
 *
 */

#include <iostream>
#include "Stack.cpp"
using namespace std;

int main ()
{
	char ch;
	while (cin.get(ch))
	{
		Stack ch_stack;
		while (ch != '\n')
		{
			if (ch == '#')
			{
				if (!ch_stack.is_empty())
				{
					ch_stack.pop ();
				}
			}
			else if (ch == '@')
			{
				while (!ch_stack.is_empty())
				{
					ch_stack.pop ();
				}
			}
			else
			{
				if (!ch_stack.is_full())
				{
					ch_stack.push (ch);
				}
			}
			cin.get (ch);
		}
		ch_stack.show_from_bottom ();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

