#include <iostream>
using namespace std;

int get_max_prime (int value)
{
	int tmp = 1;
	for (int i = 2; i < value; i++)
	{
		if (value%i==0)
		{
			tmp = i;
			while (value%i==0)
			{
				value/=i;
			}
		}
	}
	if (value!=1)
	{
		tmp=value;
	}
	return tmp;
}

int main ()
{
	int n;
	cin >> n;
	int max_value;
	int max_prime;
	cin >> max_value;
	max_prime = get_max_prime (max_value);
	for (int i = 1; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		int tmp_prime = get_max_prime (tmp);
		if (tmp_prime > max_prime)
		{
			max_value = tmp;
			max_prime = tmp_prime;
		}
	}
	cout << max_value << endl;
	return 0;
}


