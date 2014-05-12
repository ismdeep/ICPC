/*
 * main.cpp
 *
 *  Created on: May 12, 2014
 *      Author: ismdeep
 */

#include <iostream>
using namespace std;

int main ()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
}


