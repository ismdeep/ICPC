#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1100

int a[MAXN];
int b[MAXN];

int n;

int return_count ()
{
	int count = 0;
	int index;
	for (index = 1; a[index] == b[index] && index <= n; index++)
	{
		count++;
	}
	int j;
	for (j = n; j > index && a[j] == b[j]; j--)
	{
		count++;
	}
	int countt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == b[j])
		{
			countt++;
		}
		else
		{
			if (count < countt)
			{
				count = countt;
				countt = 0;
			}
		}
	}
	if (count < countt)
	{
		count = countt;
	}
	return count;
}

int main ()
{
	while (scanf ("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf ("%d", &a[i]);
			b[n-i+1] = a[i];
		}
		int max = 0;
		max = return_count ();
		for (int times = 0; times <= n / 2; times++)
		{
			int count_tmp;
			int tmp = b[1];
			for (int i = 1; i <n; i++)
			{
				b[i] = b[i+1];
			}
			b[n] = tmp;
			count_tmp = return_count ();
			if (max < count_tmp)
			{
				max = count_tmp;
			}
			for (int timess = 0; timess <= n / 2 ; timess++)
			{
				tmp = a[1];
				for (int i = 1; i < n; i++)
				{
					a[i] = a[i+1];
				}
				a[n] = tmp;
				count_tmp = return_count ();
				if (max < count_tmp)
				{
					max = count_tmp;
				}
			}
		}
		if (max == 0)
		{
			printf("%d\n", max);
		}
		else if (max >= n)
		{
			printf("%d\n", max);
		}
		else
		{
			printf("%d\n", max + 1);
		}
	}
	return 0;
}

