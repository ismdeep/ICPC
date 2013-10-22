#include <iostream>
#include <stdio.h>
using namespace std;
int t,iMap[10010],n;
int main()
{
    //freopen("in.dat", "r", stdin);
    scanf("%d",&t);
    for (int iNum = 1; iNum <= t; iNum++)
    {
        scanf("%d%d%d%d%d%d%d",&iMap[0],&iMap[1],&iMap[2],&iMap[3],&iMap[4],&iMap[5],&n);

        for (int i = 0; i <= 5; i++)iMap[i]%=10000007;
        for (int i = 6; i <= n; i++)
        {
            iMap[i]=iMap[i-1]+iMap[i-2]+iMap[i-3]+iMap[i-4]+iMap[i-5]+iMap[i-6];
            iMap[i]%=10000007;
        }
        printf("Case %d: %d\n",iNum,iMap[n]);
    }
    return 0;
}
