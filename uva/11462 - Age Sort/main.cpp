/*
 uva 11462
*/


#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int no_count[200];


int main ()
{
	int n;
	int tmp;
	while (scanf ("%d", &n) != EOF && 0 != n)
	{
		//---- init code
		for (int i = 0; i < 200; i++)
		{
			no_count[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &tmp);
			no_count[tmp]++;
		}
		int flag = false;
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < no_count[i]; j++)
			{
				if (flag)
				{
					printf (" ");
				}
				flag = true;
				printf ("%d", i);
			}
		}
		printf ("\n");
	}
	return 0;
}


