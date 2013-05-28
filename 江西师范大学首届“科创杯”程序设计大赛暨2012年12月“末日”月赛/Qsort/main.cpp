#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 220000
int iMap[MAXN];
int nSize;

int main ()
{
	while (scanf ("%d", &nSize) != EOF)
	{
		for (int i = 0; i < nSize; i++)
		{
			scanf ("%d", &iMap[i]);
		}
		sort (iMap, iMap + nSize);
		for (int i = 0; i < nSize - 1; i++)
		{
			printf ("%d ", iMap[i]);
		}
		printf ("%d\n", iMap[nSize-1]);
	}
	return 0;
}
