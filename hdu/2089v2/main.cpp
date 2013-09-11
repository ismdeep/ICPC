#include <iostream>
#include <stdio.h>
using namespace std;

/*data*/
#define MAXN 1000100
bool iMap[MAXN];

/*function*/
bool iIsBadNumber(int iNum)
{
    bool yes = false;
    while (!yes && iNum)
    {
        if (iNum % 10 == 4 || iNum % 100 == 62)
        {
            yes = true;
        }
        iNum /= 10;
    }

    return yes;
}


void iMakeMap()
{
    iMap[0] = false;
    iMap[1] = false;
    int iNum;
    for (iNum = 2; iNum < MAXN; iNum++)
    {
        if (iIsBadNumber(iNum))
        {
            iMap[iNum] = true;
        }
        else
        {
            iMap[iNum] = false;
        }
    }
}

int main()
{
    iMakeMap();
    int iStart, iEnd;
    //freopen("in.dat", "r", stdin);
    while (scanf("%d%d", &iStart, &iEnd) != EOF && iStart + iEnd)
    {
        int iCount = 0;
        for (int i = iStart; i <= iEnd; i++)
        {
            if (iMap[i])
            {

            }
            else
            {
                iCount++;
            }
        }
        cout << iCount << endl;
    }

    return 0;
}

// end
// ism























