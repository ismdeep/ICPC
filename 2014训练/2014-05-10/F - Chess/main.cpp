/*
 * main.cpp
 *
 *  Created on: May 10, 2014
 *      Author: ismdeep
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

int a[100];

int main()
{
	srand(10);
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
	}
	sort (a,a+10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

