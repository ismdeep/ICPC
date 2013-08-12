/*
 * Project     : 2012v2
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Sep  8 17:08:13 2012 
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

typedef long long int longint;


// n^2+n+41
// get value
int get_value(int n)
{
	return (n * n + n + 41);
}

bool is_prime(int num)
{
	int stop = sqrt((double)num);
	bool yes = true;
	for (int i = 2; yes && i <= stop; i++)
	{
		if (num % i == 0)
		{
			yes = false;
		}
	}
	return yes;
}

int main()
{
	// make map
	for (int i = -39; i <= 50; i++)
	{
		cout << i << " - ";
		int value;
		value = get_value(i);
		cout << value << "  -- ";
		if (is_prime(value))
		{
			cout << " is prime" << endl;
		}
		else
		{
			cout << "is not prime" << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

