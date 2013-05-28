/*
 * Project     : E
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Oct 20 09:54:06 2012 
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
using namespace std;

int get_lucky_value (int num)
{
    int time_pow = 1;
    int lucky_value = 0;
    while (num)
    {
	if (num % 10 == 4 || num % 10 == 7)
	{
	    lucky_value = lucky_value + time_pow * (num % 10);
	    time_pow *= 10;
	}
	num /= 10;
    }
    return lucky_value;
}

int main()
{
    int a, des_lucky_value;
    while (cin >> a >> des_lucky_value)
    {
	bool found = false;
	for (int i = a + 1; !found ; i++)
	{
	    if (get_lucky_value(i) == des_lucky_value)
	    {
		cout << i << endl;
		found = true;
	    }
	}
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

