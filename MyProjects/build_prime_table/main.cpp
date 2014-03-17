#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

#define MAX_VALUE 1000001


bool is_prime[MAX_VALUE];

void init_prime_table ()
{
	memset (is_prime, 1, sizeof(is_prime));
}

void make_prime_table ()
{
	for (int i = 2; i * i < MAX_VALUE; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j < MAX_VALUE; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	is_prime[0] = false;
	is_prime[1] = false;
}


int main ()
{
	init_prime_table ();
	make_prime_table ();
	cout << "Input 2 Numbers (0 ~ "<< MAX_VALUE - 1 << "): ";
	int a, b;
	cin >> a >> b;
	cout << "The primes witch is between " << a << " and " << b << ":";
	for (int i = a; i <= b; i++)
	{
		if (is_prime[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}


