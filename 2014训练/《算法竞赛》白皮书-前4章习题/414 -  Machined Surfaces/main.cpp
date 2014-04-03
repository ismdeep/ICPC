#include <iostream>
using namespace std;

int main ()
{
	int n;
	while (cin >> n, n)
	{
		// ---- what about this shit, this is the so called , XXXXXBBBBBBBBBBBBXXXX ,
		// ---- the string.
		string* str = new string[n];
		// ---- This will save how many BBBB in evey string.
		int* left = new int[n];
		// ---- scanner.. just scanner . with nothin
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			left[i] = 0;
			for (int j = 0; j < 25; j++)
			{
				if ('X' != str[i][j])
				{
					left[i]++;
				}
			}
		}
		// ----- just get the min_value of left[i];
		int min_value;
		min_value = left[0];
		for (int i = 1; i < n; i++)
		{
			if (min_value > left[i])
			{
				min_value = left[i];
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (left[i] - min_value);
		}
		cout << sum << endl;
	}
	return 0;
}

