#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned long long int longint;

#define MAXN 60

longint iMap[MAXN];

void iCreatMap()
{
    iMap[0] = 2;
    iMap[1] = 3;
    for (int i = 2; i < MAXN; i++)
    {
        iMap[i] = iMap[i-1] + iMap[i-2];
    }
}

void iShowMap()
{
    for (int i = 0; i < MAXN; i++)
    {
        cout << iMap[i] << endl;
    }
}

bool iIsInMap(longint iNum)
{
    bool iFound = false;
    for (int i = 0; !iFound && i < MAXN; i++)
    {
        if (iMap[i] == iNum)
        {
            iFound = true;
        }
    }
    return iFound;
}

int main()
{
    iCreatMap();
    //iShowMap();

    longint iNum;
    while (cin >> iNum && iNum)
    {
        if (iIsInMap(iNum))
        {
            cout << "Second win" << endl;
        }
        else
        {
            cout << "First win" << endl;
        }
    }

    return 0;
}

// end
// ism
