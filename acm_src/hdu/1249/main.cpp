#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXN 10010

typedef unsigned long long longint;

longint iMap[MAXN];

void init_map()
{
	iMap[1] = 2;
	for (int i = 2; i < MAXN; i++)
	{
		iMap[i] = iMap[i-1] + 6 * (i-1);
	}
}

int main()
{
	init_map();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << iMap[n] << endl;
	}
	return 0;
}

// end 
// iCoding
//

