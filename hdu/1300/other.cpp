#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

#define inf 210000000

int main()
{
    int T,i,j,a[105],dp[105],min,n,t,p[105];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        a[0]=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&t,&p[i]);
            a[i]=a[i-1]+t;
        }
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;++i)
        {
            min=inf;
            for (j=0;j<i;++j)
            {
                if (dp[j]+(a[i]-a[j]+10)*p[i]<min) min=dp[j]+(a[i]-a[j]+10)*p[i];
            }
            dp[i]=min;
        }
        cout << dp[n] << endl;
    }
    return 0;
}


// end
// ism
