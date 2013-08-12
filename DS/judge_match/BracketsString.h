#include <iostream>
#include "Stack.cpp"
using namespace std;

class BracketsString
{
	private:
		string brackets;
	public:
		void set_value (string str);
		bool judge_is_match ();
};


