#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long int longint;

/*data*/
#define MAXN 110
class Node
{
    public:
    longint iMax;
    longint iMin;
};
Node iMap[MAXN][MAXN];
longint n;
longint iMaxResult;
longint iMinResult;

/*process*/
void iInit()
{
    /*init some data and input data*/
    iMaxResult = 0;
    iMinResult = 0;
    for (longint j = 0; j < n; j++)
    {
        cin >> iMap[n-1][j].iMin;
        iMap[n-1][j].iMax = iMap[n-1][j].iMin;
    }
}

void iShowMap()
{
    for (longint i = 0; i < n; i++)
    {
        for (longint j = 0; j < n; j++)
        {
            cout << iMap[i][j].iMin << " ";
            iMap[i][j].iMax = iMap[i][j].iMin;
        }
        cout << endl;
    }
}
void iDynamicProgramming()
{
    /*cal for iMinReuslt*/
    for(longint i = n - 2; i >= 0; i--)
    {
        //iShowMap();
        longint index_a = -1, index_b = -1;
        for (longint j = 0; j <= i + 1; j++)
        {
            if (index_a == -1)
            {
                index_a = j;
                index_b = j + 1;
            }
            else
            {
                if (
                        (iMap[i+1][index_a].iMin + iMap[i+1][index_b]    .iMin)
                    >   (iMap[i+1][j]      .iMin + iMap[i+1][(j+1)%(i+2)].iMin)
                    )
                {
                    index_a = j;
                    index_b = (j+1) % (i+2);
                }
            }
        }
        if (index_b == 0)
        {
            iMap[i+1][0].iMin = iMap[i+1][index_b].iMin + iMap[i+1][index_a].iMin;
            iMinResult += iMap[i+1][0].iMin;
            for (longint j = 0; j <= i; j++)
            {
                iMap[i][j].iMin = iMap[i+1][j].iMin;
            }
        }
        else
        {
            iMap[i+1][index_a].iMin += iMap[i+1][index_b].iMin;
            iMinResult += iMap[i+1][index_a].iMin;
            for (longint j = 0; j <= index_a; j++)
            {
                iMap[i][j].iMin = iMap[i+1][j].iMin;
            }
            for (longint j = index_a + 1; j <= i; j++)
            {
                iMap[i][j].iMin = iMap[i+1][j+1].iMin;
            }
        }
    }
    //prlongintf("%d\n", iMinResult);
    cout << iMinResult << endl;
    /*cal for iMaxResult*/
    for(longint i = n - 2; i >= 0; i--)
    {
        //iShowMap();
        longint index_a = -1, index_b = -1;
        for (longint j = 0; j <= i + 1; j++)
        {
            if (index_a == -1)
            {
                index_a = j;
                index_b = j + 1;
            }
            else
            {
                if (
                        (iMap[i+1][index_a].iMax + iMap[i+1][index_b]    .iMax)
                    <   (iMap[i+1][j]      .iMax + iMap[i+1][(j+1)%(i+2)].iMax)
                    )
                {
                    index_a = j;
                    index_b = (j+1) % (i+2);
                }
            }
        }
        if (index_b == 0)
        {
            iMap[i+1][0].iMax = iMap[i+1][index_b].iMax + iMap[i+1][index_a].iMax;
            iMaxResult += iMap[i+1][0].iMax;
            for (longint j = 0; j <= i; j++)
            {
                iMap[i][j].iMax = iMap[i+1][j].iMax;
            }
        }
        else
        {
            iMap[i+1][index_a].iMax += iMap[i+1][index_b].iMax;
            iMaxResult += iMap[i+1][index_a].iMax;
            for (longint j = 0; j <= index_a; j++)
            {
                iMap[i][j].iMax = iMap[i+1][j].iMax;
            }
            for (longint j = index_a + 1; j <= i; j++)
            {
                iMap[i][j].iMax = iMap[i+1][j+1].iMax;
            }
        }
    }
    //prlongintf("%d\n", iMaxResult);
    cout << iMaxResult << endl;
}

/*main*/
int main()
{
    //freopen("in.dat", "r", stdin);
    while (cin >> n)
    {
        if (n == 1)
        {
            longint tmp;
            cin >> tmp;
            cout << tmp << endl << tmp << endl;
            continue;
        }
        iInit();
        //iShowMap();
        iDynamicProgramming();
    }
    return 0;
}

// end
// ism
