#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


class BigInteger
{
public:
	int iData[4000];
	int iTop;
	//
	BigInteger ();
	void show ();
	friend BigInteger operator + (BigInteger big_a, BigInteger big_b);
	friend BigInteger operator * (BigInteger big_a, int int_b);
};


BigInteger::BigInteger ()
{
	int iTop = -1;
	memset (iData, 0, sizeof(iData));
}

void BigInteger::show ()
{
	for (int i = iTop; i >= 0; i--)
	{
		printf ("%d", iData[i]);
	}
	printf ("\n");
}

BigInteger operator + (BigInteger big_a, BigInteger big_b)
{
	BigInteger big_sum;
	big_sum.iTop = big_a.iTop;
	if (big_b.iTop > big_a.iTop)
	{
		big_sum.iTop = big_b.iTop;
	}
	for (int i = 0; i <= big_sum.iTop; i++)
	{
		big_sum.iData[i] = big_a.iData[i] + big_b.iData[i];
	}
	big_sum.iTop += 5;
	for (int i = 0; i < big_sum.iTop; i++)
	{
		big_sum.iData[i+1] += (big_sum.iData[i] / 10);
		big_sum.iData[i]   %= 10;
	}
	while (big_sum.iData[big_sum.iTop] == 0)
	{
		big_sum.iTop--;
	}
	return big_sum;
}

BigInteger operator * (BigInteger big_a, int int_b)
{
	BigInteger big_sum;
	big_sum.iTop = big_a.iTop;
	for (int i = 0; i <= big_a.iTop; i++)
	{
		big_sum.iData[i] = big_a.iData[i] * int_b;
	}
	//
	big_sum.iTop += 7;
	for (int i = 0; i < big_sum.iTop; i++)
	{
		big_sum.iData[i+1] += (big_sum.iData[i] / 10);
		big_sum.iData[i]   %= 10;
	}
	while (0 == big_sum.iData[big_sum.iTop])
	{
		big_sum.iTop--;
	}
	return big_sum;
}

//-----------------------------------------------------------------//

BigInteger iMap[2000];

void make_iMap ()
{
	iMap[0].iData[0] = 1;
	iMap[0].iTop     = 0;
	for (int i = 1; i < 1100; i++)
	{
		iMap[i] = iMap[i-1] * i;
	}
}

int main ()
{
	make_iMap ();
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		BigInteger big_sum;
		big_sum = iMap[x] + iMap[x-1];
		big_sum.show ();
	}
	int a, b;
}



