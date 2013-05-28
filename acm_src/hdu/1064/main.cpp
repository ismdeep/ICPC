// Project name : 1064 ( Financial Management )
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Thu Jul  5 20:51:14 2012


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double sum = 0.0;
	for (int i = 0; i < 12; i++)
	{
	    double tmp;
		cin >> tmp;
		sum += tmp;
	}

	sum /= 12;

	printf("$%.2f\n", sum);
    return 0;
}

// end 
// ism 

