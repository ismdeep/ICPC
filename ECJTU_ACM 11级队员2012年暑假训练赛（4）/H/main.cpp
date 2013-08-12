#include <iostream>
using namespace std;

#define MAXN 100

int a[MAXN][MAXN];

int n;

void dp()
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[i+1][j] > a[i+1][j+1])
            {
                a[i][j] += a[i+1][j];
            }
            else
            {
                a[i][j] += a[i+1][j+1];
            }
        }
    }
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{
    while (cin >> n)
    {
        init();
        dp();
        cout << a[0][0] << endl;
    }

    return 0;
}

// end
// ism
