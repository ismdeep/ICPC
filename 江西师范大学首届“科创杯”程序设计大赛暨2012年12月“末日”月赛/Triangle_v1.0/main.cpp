#include <iostream>
using namespace std;

#define MOD 100
#define MAXN 50

int iMap[MAXN][MAXN];
int nSize;

int main ()
{
	while (cin >> nSize)
	{
		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> iMap[i][j];
			}
		}
		//-- DP ----//
		for (int i = nSize - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				if ((iMap[i][j] + iMap[i+1][j]) % MOD >= (iMap[i][j] + iMap[i+1][j+1]) % MOD)
				{
					iMap[i][j] = (iMap[i][j] + iMap[i+1][j]);
				}
				else
				{
					iMap[i][j] = (iMap[i][j] + iMap[i+1][j+1]);
				}
			}
		}
		cout << iMap[0][0] % 100 << endl;
	}
	return 0;
}


