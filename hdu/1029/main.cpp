#include <iostream>
#include <stdio.h>
using namespace std;

int a[32769];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < 32769; i++)
	{
	    a[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
	    int tmp;
	    //cin >> tmp;
	    scanf("%d", &tmp);
	    a[tmp]++;
	}

	int max = 0;
	for (int i = 1; i < n; i++)
	{
	    if (a[i] > a[max])
	    {
	        max = i;
	    }
	}

	printf("%d\n", max);

    }

    return 0;
}

// end 
// ism 

