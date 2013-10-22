// Project name : 1157 ( Who's in the Middle ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 20:42:15 2012


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
	while (cin >> n)
	{
	    int* a = new int[n];
		int top = n - 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		for (int t = 0; t < n / 2; t++)
		{
		    int flag = 0;
			for (int i = 1; i <= top; i++)
			{
			    if (a[i] > a[flag])
				{
				    flag = i;
				}
			}
			a[flag] = a[top];
			top--;
		}

		int flag = 0;
		for (int i = 0; i <= top; i++)
		{
		    if (a[i] > a[flag])
			{
			    flag = i;
			}
		}

		cout << a[flag] << endl;

		delete[] a;
	}
    return 0;
}

// end 
// ism 

