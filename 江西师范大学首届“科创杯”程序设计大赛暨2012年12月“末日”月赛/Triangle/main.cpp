#include <iostream>
using namespace std;

#define MOD 100
#define MAXN 50

int iMap[MAXN][MAXN];
int nSize;
int iMaxModValue;

int iTmpSum;

void iTry (int i, int j, int level)
{
	if (level == nSize)
	{
		iMaxModValue = (iTmpSum % 100 > iMaxModValue) ? iTmpSum % 100 : iMaxModValue;
	}
	else
	{
		iTmpSum += iMap[i][j];
		iTry (i + 1, j    , level + 1 );
		iTry (i + 1, j + 1, level + 1 );
		iTmpSum -= iMap[i][j];
	}
}

int main ()
{
	while (cin >> nSize)
	{
		iMaxModValue = -1;
		iTmpSum = 0;
		for (int i = 0; i < nSize; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> iMap[i][j];
			}
		}
		iTry (0, 0, 0);
		cout << iMaxModValue << endl;
	}
	return 0;
}


