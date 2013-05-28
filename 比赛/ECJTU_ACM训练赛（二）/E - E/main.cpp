#include <iostream>
#include <cstdio>
using namespace std;

int iGetValue(int x)
{
    return (x ^ (x >> 1));
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << m); j++)
        {
            printf("%d ",(iGetValue(i) << m) + iGetValue(j));
        }
        printf("\n");
    }
    return 0;
}

