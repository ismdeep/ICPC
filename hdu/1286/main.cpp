#include <iostream>
#include <cmath>
using namespace std;

int phi(int num)
{
	int sum = 1;
	for (int i = 2; i <= sqrt((double)num); i++)
{
		if (num % i == 0)
		{
			while (num % i == 0)
			{
				sum *= i;
				num /= i;
			}
			sum /= i;
			sum *= (i-1);
		}
	}
	if (num != 1)
	{
		sum *= (num-1);
	}
	return sum;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		cout << phi(num) << endl;
	}
	return 0;
}

// end 
// iCoding

