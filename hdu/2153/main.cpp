#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#ifndef MAXN
#define MAXN 100
#endif

int iMap[MAXN][MAXN];
int n;

void iInit()
{
	memset(iMap, 0, sizeof(iMap));
}

void iDraw()
{
	int iCurrent = 0;
	for (int j = 0; j < n; j++)
	{
		iCurrent++;
		iMap[0][j] = iCurrent;
	}
	for (int i = 1; i < n; i++)
	{
		iCurrent++;
		iMap[i][n-1] = iCurrent;
	}
	for (int j = n - 2; j >= 0; j--)
	{
		iCurrent++;
		iMap[n-1][j] = iCurrent;
	}
	for (int i = n - 2; i >= 1; i--)
	{
		iCurrent++;
		iMap[i][0] = iCurrent;
	}
}

void iOutput()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//
			//
			//
			if (iMap[i][j] == 0)
			{
				cout << "   ";
			}
			else if (iMap[i][j] < 10)
			{
				cout << "  " << iMap[i][j];
			}
			else
			{
				cout << " " << iMap[i][j];
			}
		}
		cout << endl;
	}
}

int main()
{
	while (cin >> n)
	{
		iInit();
		iDraw();
		iOutput();
	}
	return 0;
}

// end
// iCoding
//

