// Project name : B
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 12:31:04 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n + m)
    {
        if(n % 2 == 0 || m % 2 == 0)
		{
			printf("Wonderful!\n");
		}
		else
		{
			printf("What a pity!\n");
		}
    }
    return 0;
}


// end 
// ism 

