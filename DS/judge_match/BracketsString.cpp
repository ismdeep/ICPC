#include <iostream>
#include "BracketsString.h"
using namespace std;


/////////////////////////////////////////////////////////////////////
// set value for BracketsString
void BracketsString::set_value (string str)
{
	this -> brackets = str;
}

/////////////////////////////////////////////////////////////////////
// judge if brackets is match
bool BracketsString::judge_is_match ()
{
	Stack stack;
	int top = this -> brackets.length() - 1;
	for (int i = 0; i <= top; i++)
	{
		// push or pop that doesn't matter
		// Who cares
		// Come on! Let's get start
		if (stack.is_empty())
		{
			stack.push(this->brackets[i]);
		}
		else
		{
			char top_char = stack.get_top ();
			if (top_char == '[' && this -> brackets[i] == ']')
			{
				stack.pop();
			}
			else if (top_char == '(' && this -> brackets[i] == ')')
			{
				stack.pop();
			}
			else if (top_char == '{' && this -> brackets[i] == '}')
			{
				stack.pop();
			}
			else
			{
				stack.push (this -> brackets[i]);
			}
		}
	}
	return (stack.is_empty());
}
