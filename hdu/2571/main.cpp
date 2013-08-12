#include <iostream>
using namespace std;

#define MAXN 25
#define MAXM 1010

typedef long long int longint;

int iMap[MAXN][MAXM]; /* using 1 - n ,, 1 - m to store data ... you know the rule.*/

int n, m;

longint MIN_NUMBER = -1 << 31;

bool iHeadOfLine(int x, int y)
{
    return y == 1 ? true : false;
}

void iInit()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> iMap[i][j];
        }
    }

    for (int j = 0; j <= m; j++)
    {
        iMap[0][j] = MIN_NUMBER;
    }

    for (int i = 0; i <= n; i++)
    {
        iMap[i][0] = MIN_NUMBER;
    }
    iMap[1][0] = 0;
    iMap[0][1] = 0;
}

void iDynamicProgramming()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int iMax;
            iMax = iMap[i][j-1];
            if (iMax < iMap[i-1][j])
            {
                iMax = iMap[i-1][j];
            }

            for (int k = 1; k < j; k++)
            {
                if (j % k == 0)
                {
                    if (iMax < iMap[i][k])
                    {
                        iMax = iMap[i][k];
                    }
                }
            }

            iMap[i][j] += iMax;
        }
    }
}

void iShowResult()
{
    cout << iMap[n][m] << endl;
}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        iInit();

        iDynamicProgramming();

        iShowResult();

    }

    return 0;
}

// end
// ism
