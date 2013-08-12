#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

string ok = "OK";
string sorry = "Sorry";

int data[4] = {40, 41, 44, 49};

bool is_prime(int num)
{
	int stop = sqrt((double)num);
	bool yes = true;
	for (int i = 2; yes && i <= stop; i++)
	{
		if (num % i == 0)
		{
			yes = false;
		}
	}
	return yes;
}


int get_value(int n)
{
	return (n * n + n + 41);
}


int main()
{
	int x, y;
	while (scanf("%d%d", &x, &y) != EOF && x + y)
	{
		bool yes = true;
		for (int i = x; i <= y; i++)
		{
			int value = get_value(i);
			if (is_prime(value))
			{
			}
			else
			{
				yes = false;
			}
		}
		if (yes)
		{
			cout << ok << endl;
		}
		else
		{
			cout << sorry << endl;
		}
	}
	return 0;
}



