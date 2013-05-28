#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

#define MOD 10007

class BigInteger
{
public:
	int iData[444000];
	int iTop;
	int remainder;
	//
	BigInteger ();
	void mul (int num);
	void div (int num);
};

BigInteger::BigInteger ()
{
	iTop = 0;
	memset (iData, 0, sizeof(iData));
	iData[0] = 1;
}

void BigInteger::mul (int num)
{
	for (int i = 0; i <= iTop; i++)
	{
		iData[i] *= num;
	}
	iTop += 5;
	for (int i = 0; i < iTop; i++)
	{
		iData[i+1] += (iData[i] / 10);
		iData[i]   %= 10;
	}
	//
	while (0 == iData[iTop])
	{
		iTop--;
	}
}

void BigInteger::div (int num)
{
	for (int i = iTop; i > 0; i--)
	{
		iData[i-1] += ((iData[i] % num) * 10);
		iData[i]   /= num;
	}
	remainder = iData[0] % num;
	iData[0] /= num;
	while (0 == iData[iTop])
	{
		iTop--;
	}
}

int a, b, k, n, m;

int main ()
{
	while (cin >> a >> b >> k >> n >> m)
	{
		BigInteger sum;
		//
		for (int i = 1; i <= k; i++)
		{
			sum.mul (i);
		}
		for (int i = 1; i <= n; i++)
		{
			sum.div (i);
		}
		for (int i = 1; i <= (k - n); i++)
		{
			sum.div (i);
		}
		//
		for (int i = 1; i <= n; i++)
		{
			sum.mul (a);
		}
		for (int i = 1; i <= m; i++)
		{
			sum.mul (b);
		}
		//
		sum.div (MOD);
		if (k == 0)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << sum.remainder << endl;
		}
	}
	return 0;
}
