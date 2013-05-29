#include <iostream>
using namespace std;

#define MAXN 210

typedef unsigned long long int longint;

const longint INF = 1 << 31;

longint a[MAXN];

longint dp[MAXN][MAXN];

int n;

void iInit()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void iDynamicProgramming()
{
    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = i + 2; j <= n; j++)
        {
            longint max = INF;
            for (int k = i + 1; k <= j - 1; k++)
            {
                if (max > dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])
                {
                    max = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
                }
            }
            dp[i][j] = max;
        }
    }
}

void iShowResult()
{
    cout << dp[1][n] << endl;
}

int main()
{

    while (cin >> n)
    {
        iInit();

        iDynamicProgramming();

        iShowResult();

    }
    return 0;
}

// end
// ism
