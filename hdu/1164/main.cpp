// Project name : 1164 ( Eddy's research I ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 21:07:17 2012


#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int num;
	while (cin >> num)
	{
	    int* prime;
		prime =new int[1000];
		int top = -1;
		int current_prime = 2;

		int CGetNextPrime(int);

		while (num != 1)
		{
		    if (num % current_prime == 0)
			{
			    top++;
				prime[top] = current_prime;
				num /= current_prime;
			}
			else
			{
			    current_prime = CGetNextPrime(current_prime);
			}
		}

		// output 
		for (int i = 0; i < top; i++)
		{
		    cout << prime[i] << "*";
		}
		cout << prime[top] << endl;

	}
    return 0;
}
/*********************************************************************/
bool CIsPrime(int k)
{
    int stop = sqrt(k);
	bool yes = true;
	for (int i = 2; yes && i <= stop; i++)
	{
	    if (k % i == 0)
		{
		    yes = false;
		}
	}
	return yes;
}
/*********************************************************************/
int CGetNextPrime(int num)
{
	num++;
	while (!CIsPrime(num))
	{
	    num++;
	}
	return num;
}
// end 
// ism 

