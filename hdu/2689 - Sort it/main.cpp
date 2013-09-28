#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main ()
{
	int n;
	while (scanf ("%d", &n) != EOF)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &arr[i]);
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n - 2; j++)
			{
				if (arr[j] > arr[j+1])
				{
					int tmp = arr[j];
					arr[j]  = arr[j+1];
					arr[j+1]= tmp;
					count++;
				}
			}
		}
		printf ("%d\n", count);
	}
	return 0;
}


