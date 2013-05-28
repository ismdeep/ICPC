/*
 * Project     : get_pair
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Tue Sep 25 08:16:05 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
#include "BracketsString.cpp"
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		BracketsString brackets_string;
		// set value for brackets_string
		brackets_string.set_value (str);
		// get judge value
		bool is_match;
		is_match = brackets_string.judge_is_match ();
		// output msg if str is match
		if (is_match)
		{
			cout << str << " is match." << endl;
		}
		else
		{
			cout << str << " is not match." << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

