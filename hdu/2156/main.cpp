#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		double sum = 0.0;
		sum += ((double)1 * n);
		for (int i = 2; i <= n; i++)
		{
			double tmp;
			tmp = ((double)1 / i);
			tmp *= (double)2;
			tmp *= (double)(n - i + 1);
			sum += tmp;
		}
		printf("%.2f\n", sum);
	}
	return 0;
}

// end 
// iCoding
//

