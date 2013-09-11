#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <sstream>
using namespace std;

typedef long long int LL;

LL get_digital_sum (int value)
{
	int sum = 0;
	while (value)
	{
		sum += (value % 10);
		value /= 10;
	}
	return sum;
}



LL force (int a, int b, int mod)
{
	int count = 0;
	for (int i = a; i <= b; i++)
	{
		if (get_digital_sum(i) % 10 == 0)
		{
			count++;
		}
	}
	return count;
}


bool right (int value)
{
	return (get_digital_sum(value) % 10 == 0);
}



int main (int argc, char** argv)
{
	string str = argv[1];
	stringstream ou;
	ou << str << endl;
	int seed;
	ou >> seed;
	srand (seed);
	int n;
	n = 1000000;
	int count = 0;
	while (n--)
	{
		LL a;
		a = rand () % 1000000;
		bool found = false;
		for (int i = 0; i < 10; i++)
		{
			if (right(a+i))
			{
				found = true;
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}

