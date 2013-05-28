#include <iostream>
using namespace std;

#define MAXN 11

#define QUEUE true
#define BLANK false

bool b_map[MAXN][MAXN];
int n;
int count_total;

void init_b_map ()
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			b_map[i][j] = BLANK;
		}
	}
}

bool judge_legal (int x, int y)
{
}

void try_put (int x, int y)
{
	if (judge_legal(x, y))
	{
		if (n - 1 <= y)
		{
			count_total++;
		}
		else
		{
			b_map[x][y] = QUEUE;
			for (int x_index = 0; x_index < n; x_index++)
			{
				try_put(x_index, y + 1);
			}
			b_map[x][y] = BLANK;
		}
	}
}

int main ()
{
	while (cin >> n)
	{
		count_total = 0;
		for (int x_index = 0; x_index < n; x_index++)
		{
			try_put(x_index, 0);
		}
	}
	return 0;
}

