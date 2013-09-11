#include <iostream>
#include <stdio.h>
using namespace std;

/*data*/
#define MAXN 1000100
bool ibad[MAXN];


/*function*/
bool iIsBadNumber(int num)
{
    bool yes = false;
    while (!yes && num)
    {
        if (num % 10 == 4 || num % 100 == 62)
        {
            yes = true;
        }
        num = num / 10;
    }
    return yes;
}

void iInit()
{
    ibad[0] = false;
    ibad[1] = false;
    for (int i = 2; i < MAXN; i++)
    {
        ibad[i] = !iIsBadNumber(i);
    }
}

int main()
{
    iInit();
    //iShow();
    //freopen("in.dat", "r", stdin);
    int start, end;
    while (scanf("%d%d", &start, &end) && start + end)
    {
        int count = 0;
        for (int i = start; i <= end; i++)
        {
            if (ibad[i])
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
