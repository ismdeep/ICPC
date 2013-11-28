#include <iostream>
using namespace std;

#ifndef MAXN
#define MAXN 2000000
#endif

#ifndef MOD
#define MOD 3
#endif

int iMap[MAXN+1];

void make_iMap()
{
    iMap[0] = 7 % MOD;
    iMap[1] = 11 % MOD;
    for (int i = 2; i <= MAXN; i++)
    {
	iMap[i] = (iMap[i-1] + iMap[i-2]) % MOD;
    }
}

int main()
{
    make_iMap ();
    int index;
    while (cin >> index)
    {
	if (0 == iMap[index])
	{
	    cout << "yes" << endl;
	}
	else
	{
	    cout << "no"  << endl;
	}
    }
    return 0;
}
//end
//ism
