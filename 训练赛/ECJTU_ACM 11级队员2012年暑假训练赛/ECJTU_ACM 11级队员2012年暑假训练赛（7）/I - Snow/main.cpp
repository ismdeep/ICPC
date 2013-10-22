#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

struct Node
{
    int x;
    int y;
    int heigt;
};

bool cmp(Node a, Node b)
{
    return (a.heigt < b.heigt) ? true : false;
}

int iMap[MAXN][MAXN];
int iMapCount[MAXN][MAXN];
Node iMapLog[MAXN * MAXN];
int iLogIndex;
int n, m;

int dir_x[4] = {-1, 0, 1,  0};
int dir_y[4] = { 0, 1, 0, -1};

bool iCanGo(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void iInit()
{
    memset(iMap, 0, sizeof(iMap));
    memset(iMapCount, 0, sizeof(iMapCount));
    memset(iMapLog, 0, sizeof(iMapLog));

    iLogIndex = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &iMap[i][j]);
            iLogIndex++;
            iMapLog[iLogIndex].x     = i;
            iMapLog[iLogIndex].y     = j;
            iMapLog[iLogIndex].heigt = iMap[i][j];
        }
    }
}

void iDynamicProgramming()
{
    sort(iMapLog,iMapLog + iLogIndex + 1, cmp);


    /*start kernel of Dynamic Programming*/
    for (int i = 0; i <= iLogIndex; i++)
    {
        int flag_x = 0;
        int flag_y = 0;

        for (int j = 0; j < 4; j++)
        {
            int next_x, next_y;
            next_x = iMapLog[i].x + dir_x[j];
            next_y = iMapLog[i].y + dir_y[j];
            if (iCanGo(next_x, next_y))
            {
                if (iMap[next_x][next_y] < iMap[iMapLog[i].x][iMapLog[i].y])
                {
                    if (flag_x == 0 && flag_y == 0)
                    {
                        flag_x = next_x;
                        flag_y = next_y;
                    }
                    else if (iMapCount[next_x][next_y] > iMapCount[flag_x][flag_y])
                    {
                        flag_x = next_x;
                        flag_y = next_y;
                    }
                }
            }
        }
        if (flag_x == 0 && flag_y == 0)
        {
            iMapCount[iMapLog[i].x][iMapLog[i].y] = 1;
        }
        else
        {
            iMapCount[iMapLog[i].x][iMapLog[i].y] = iMapCount[flag_x][flag_y] + 1;
        }
    }
}

void iGetMax()
{
    int max = iMapCount[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (iMapCount[i][j] > max)
            {
                max = iMapCount[i][j];
            }
        }
    }
    cout << max << endl;
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        iInit();
        iDynamicProgramming();
        iGetMax();
    }
    return 0;
}

// end
// ism
