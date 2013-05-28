#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 332767

bool is_prime [MAXN];

void make_is_prime ()
{
    for (int i = 0; i < MAXN; i++)
    {
	is_prime[i] = true;
    }
    for (int i = 2; i * i < MAXN; i++)
    {
	if (true == is_prime[i])
	{
	    for (int j = i * i ; j < MAXN; j += i)
	    {
		is_prime[j] = false;
	    }
	}
    }
    is_prime[0] = false;
    is_prime[1] = false;
}

int main()
{
    int iNum;
    while (cin >> iNum && iNum)
    {
	int iCount = 0;
	for (int i = 1; i * 2 <= iNum; i++)
	{
	    if(is_prime[i] && is_prime[iNum - i])
	    {
		iCount++;
	    }
	}
	cout << iCount << endl;
    }
    return 0;
}


