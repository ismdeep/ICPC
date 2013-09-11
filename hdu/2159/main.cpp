#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define MAXN 110

int c1[MAXN], c2[MAXN], w[MAXN];
int bag[MAXN][MAXN];

int n, V, N, S;

void _td_bag_dp()
{
	memset(bag, 0, sizeof(bag));
	for (int i = 0; i < N; i++)
	{
		for (int j = c1[i]; j <= V; j++)
		{
			for (int k = c2[i]; k <= S; k++)
			{
				bag[j][k] = max(bag[j][k], bag[j-c1[i]][k-c2[i]] + w[i]);
			}
		}
	}
}

int main()
{
	while (cin >> n >> V >> N >> S)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> w[i] >> c1[i];
			c2[i] = 1;
		}
		_td_bag_dp();
		int tmp;
		bool found = false;
		for (int i = 0; !found && i <= V; i++)
		{
			if (bag[i][S] >= n)
			{
				found = true;
				tmp = i;
			}
		}
		if (found)
		{
			cout << V - tmp << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

