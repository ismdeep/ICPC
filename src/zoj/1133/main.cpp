// Project name : 1133 ( Smith Numbers ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sat Jul  7 20:54:09 2012


#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

void ism()
{
    cout << "---testMsg---" << endl;
}

/****************************************************/
bool CIsPrime(int k)
{
	bool yes = true;
	int stop = sqrt(k);

	for (int i = 2;yes && i <= stop; i++)
	{
		if (k % i == 0)
		{
		    yes = false;
		}
	}

	return yes;
}
/****************************************************/
int CGetNum(int k)
{
    int result = 0;
	while (k)
	{
	    result += (k % 10);
		k /= 10;
	}
	return result;
}

/****************************************************/
int CGetPrime(int k)
{
    int current_prime = 2;
	int result        = 0;

	while (k != 1)
	{
		if (CIsPrime(k))
		{
		    current_prime = k;
		}

	    if (k % current_prime == 0)
		{
			result += CGetNum(current_prime);
			k = k / current_prime;
		}
		else
		{
			int CFindNextPrime(int);
		    current_prime = CFindNextPrime(current_prime);
		}
	}

	return result;
}

/****************************************************/
int CFindNextPrime(int k)
{
	k++;
	while (!CIsPrime(k))
	{
	    k++;
	}
	return k;
}

/****************************************************/
int main()
{
    int num;
	while (cin >> num && num)
	{
	    int yes = false;
		while (!yes)
		{
		    num++;
			if (CGetNum(num) == CGetPrime(num))
			{
			    yes = true;
			}
		}
		cout << num << endl;
	}
    return 0;
}

// end 
// ism 

