#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("in.dat", "r", stdin);
    int n;

    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", n);
    }
    return 0;
}

