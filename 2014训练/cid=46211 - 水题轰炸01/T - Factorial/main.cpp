/*
 * main.cpp
 *
 *  Created on: May 12, 2014
 *      Author: ismdeep
 */

#include <iostream>
using namespace std;

typedef long long int longint;

longint a[21];

void init ()
{
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= 20; i++)
	{
		a[i] = a[i-1]*i;
	}
}

int main ()
{
	init();
	int n;
	while (cin >> n)
	{
		cout << a[n] << endl;
	}
	return 0;
}


