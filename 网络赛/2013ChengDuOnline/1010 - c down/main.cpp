#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

#define INF 0x3fffffff
#define N 110000

typedef long long int LL;


int g[N];
int arr[33][100100];
int n, m;

LL tmp_value;
LL tmp, ans;
int pre;


int main()
{
    int T;
    int tt=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(arr,0,sizeof(arr));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n; i++)
        {
            scanf("%d", &g[i]);
            int count=1;
            int tmp=g[i];
            for(int j=1;j<=30;j++)
                arr[j][i]=arr[j][i-1];
            while(tmp)
            {
                arr[count][i] += (tmp&1);
                count++;
                tmp /= 2;
            }
        }

        ans = 0;
        tmp = 0;
        pre = 1;

        for(int i=1;i<=n;i++)
        {
            tmp_value=0;
            bool go_on = true;
            while(go_on)
            {
                tmp_value=0;
                for(int j=30;j>=1;j--)
                {
                    if( (arr[j][i]-arr[j][pre-1])!=0)
                    {
                        tmp_value = tmp_value*2+1;
                    }
                    else
                    {
                        tmp_value = tmp_value*2;
                    }
                }
                if(tmp_value>=m)
                {
                    pre++;
                }
                else
                {
                    go_on = false;
                }
            }
            ans += i-pre+1;
        }
        printf("Case #%d: ", tt++);
        printf("%I64d\n", ans);
    }
    return 0;
}

