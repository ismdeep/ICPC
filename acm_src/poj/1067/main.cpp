/*
 * Project     : 1067
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Oct 06 13:08:00 2012 
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
using namespace std;

typedef unsigned long long int longint;


int main()
{
	longint a, b;
	while (cin >> a >> b)
	{
		longint tmp;
		tmp = (a > b) ? a - b : b - a;
		cout << 1 - (tmp % 2) << endl;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

