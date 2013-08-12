#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1010

int value[MAXN];
int cost[MAXN];

int dp[MAXN][MAXN];

int n, v;

int max(int a, int b)
{
    return (a > b) ? a: b;
}
void DynamicProgramming()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            if (cost[i] <= j)
            {
                dp[i][j] = max(
                               dp[i-1][j],
                               dp[i-1][j-cost[i]] + value[i]
                               );
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> v;
        // input value []
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i];
        }

        // input cost[]
        for (int i= 1; i <= n; i++)
        {
            cin >> cost[i];
        }

        DynamicProgramming();

        cout << dp[n][v] << endl;
    }

    return 0;
}

 // end
 // ism
