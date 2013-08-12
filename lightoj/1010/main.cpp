#include <iostream>
using namespace std;

#ifndef MAXN
#define MAXN 220
#endif

bool iMap[MAXN][MAXN];

int  iMapSum[MAXN][MAXN];

void iArrangeItem(int& n, int& m)
{
	if (n > m)
	{
		int tmp;
		tmp = n;
		n   = m;
		m   = tmp;
	}
}

void iShowMapSum()
{
	const int M = 10;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << iMapSum[i][j] << " ";
		}
		cout << endl;
	}
}
int iInitMap()
{
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = 1; j < MAXN; j++)
		{
			iMap[i][j] = !((i + j) % 2);
		}
	}

	/* init for iMapSum */
	for (int j = 1; j < MAXN; j++)
	{
		iMapSum[1][j] = (j + 1) / 2;
	}

	for (int i = 2; i < MAXN; i++)
	{
		for (int j = 1; j < MAXN; j++)
		{
			int iTmpCount = 0;
			for (int jj = 1; jj < j; jj++)
			{
				if (iMap[i][jj])
				{
					iTmpCount++;
				}
			}
			iMapSum[i][j] = iMapSum[i-1][j] + iTmpCount;
			iMapSum[i][j] += (iMap[i][j]) ? 1 : 0;
		}
	}
}

void iCalForResult(int n, int m)
{
	/*
	int iAnswer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			iAnswer += (iMap[i][j])? 1 : 0 ;
		}
	}

	int tmp = n * m ;
	tmp -= iAnswer;
	if (tmp > iAnswer)
	{
		iAnswer = tmp;
	}

	*/

	if (n == 1)
	{
		cout << m << endl;
		return;
	}
	else if (n == 2)
	{
		int mod4 = m % 4;
		int iTmpAnswer = (m - mod4) / 4;
		iTmpAnswer = iTmpAnswer * 4;
		if (mod4 == 1)
		{
			iTmpAnswer += 2;
		}
		else if (mod4 >= 2)
		{
			iTmpAnswer += 4;
		}
		cout << iTmpAnswer << endl;
		return;
	}
	cout << iMapSum[n][m] << endl;
}



int main(int argc, char const *argv[])
{
	iInitMap();
	//iShowMapSum();
	int iT;
	cin >> iT;
	//while (iT--)
	for (int iCaseCount = 1; iCaseCount <= iT; iCaseCount++)
	{
		int n, m;
		cout << "Case " << iCaseCount << ": ";
		cin >> n >> m;
		iArrangeItem(n, m);
		//cout << n << " " << m << endl;
		iCalForResult(n, m);
	}
	return 0;
}

// end 
// iCoding@CodeLab

