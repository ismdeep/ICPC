#include <iostream>
#include <cstdio>
using namespace std;

#define M 200055

int a[M], b[M];

int main()
{
    int m, n, i, j;
    while (scanf ("%d%d", &m, &n) != EOF)
    {
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
                scanf ("%d", &b[j]);
            for (j = 2; j <= n; j++)
                b[j] = max (b[j-2]+b[j], b[j-1]);
            a[i] = b[n];
        }
        for (i = 2; i <= m; i++)
            a[i] = max (a[i]+a[i-2], a[i-1]);
        printf ("%d\n", a[m]);
    }
    return 0;
}

// end
// ism
