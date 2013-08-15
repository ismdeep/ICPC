#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long int LLINT;

int main ()
{
	LLINT value;
	while (cin >> value, value)
	{
		//cout << value << " =";
		printf ("%d =", value);
		if (value < 0)
		{
			//cout << " -1 x";
			printf (" -1 x");
			value = 0 - value;
		}
		bool flag = false;

		int half = (int)sqrt ((double)value + (double)0.05555);

		for (int i = 2; i <= half; i++)
		{
			if (value % i == 0)
			{
				while (value % i == 0)
				{
					if (flag)
					{
						//cout << " x";
						printf (" x");
					}
					flag = true;
					//cout << " " << i;
					printf (" %d", i);
					value /= i;
				}
			}
		}

		if (value != 1)
		{
			if (flag)
			{
				//cout << " x";
				printf (" x");
			}
			flag = true;
			//cout << " " << value;
			printf (" %d", value);
		}

		//cout << endl;
		printf ("\n");
	}
	return 0;
}

