/*
 * main.cpp
 *
 *  Created on: May 11, 2014
 *      Author: ismdeep
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long int longint;

longint gcd (longint a, longint b)
{
	longint tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


int main ()
{

	longint a, b;
	while (cin >> a >> b)
	{
		longint gcd_value, lcm_value;
		gcd_value = gcd (a,b);
		lcm_value = a * b / gcd_value;
		cout << gcd_value << " " << lcm_value << endl;
	}
	return 0;
}




