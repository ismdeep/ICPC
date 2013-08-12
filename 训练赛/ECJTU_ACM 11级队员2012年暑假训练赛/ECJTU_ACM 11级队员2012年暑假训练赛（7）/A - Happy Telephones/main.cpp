#include <iostream>
#include <stdio.h>
using namespace std;
struct Phone
{
    int iSource;
    int iDestination;
    int iStart;
    int iDuring;
};

Phone iPhone[10001];

int main()
{
    //freopen("in.dat", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n + m)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &iPhone[i].iSource, &iPhone[i].iDestination, &iPhone[i].iStart, &iPhone[i].iDuring);
        }

        for (int i = 0; i < m; i++)
        {
            int iStart, iDuring;
            int iSum = 0;
            scanf("%d%d", &iStart, &iDuring);
            for (int j = 0; j < n; j++)
            {
                if (iPhone[j].iStart < iStart && iPhone[j].iStart + iPhone[j].iDuring > iStart)
                {
                    iSum++;
                }
                if (iPhone[j].iStart == iStart)
                {
                    iSum++;
                }
                if (iPhone[j].iStart > iStart && iStart + iDuring > iPhone[j].iStart)
                {
                    iSum++;
                }
            }
            printf("%d\n", iSum);
        }
    }
    return 0;
}


// end
// iCoding@CodeLab
