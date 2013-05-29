// Project name : J
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 12:41:53 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int t;
	scanf("%d", &t);
	while (t--)
	{
	    int n;
		scanf("%d", &n);

		int sum = 0;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
			if (tmp > max)
			{
				max = tmp;
			}
		}

		sum -= max;

		if (sum >= max)
		{
			printf("Yes\n");
		}
		else
		{
		    printf("No\n");
		}


	}

	return 0;
}
// end 
// ism 

