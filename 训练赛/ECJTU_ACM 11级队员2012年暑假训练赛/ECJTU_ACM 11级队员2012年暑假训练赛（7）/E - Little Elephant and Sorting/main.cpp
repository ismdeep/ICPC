#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned long long int longint;

#define MAXN 100100

longint iMap[MAXN];
longint n;

void iInit()
{
    for (longint i = 0; i < n; i++)
    {
        cin >> iMap[i];
    }
}

void iCalAnswer()
{
    longint iCount = 0;
    for (longint i = 1; i < n; i++)
    {
        if (iMap[i] < iMap[i-1])
        {
            iCount += (iMap[i-1] - iMap[i]);
        }
    }
    cout << iCount << endl;
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (cin >> n)
    {
        iInit();
        iCalAnswer();
    }
    return 0;
}
