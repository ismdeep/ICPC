#include<stdio.h>
#include<iostream>
using namespace std;
#define N 10010

int main()
{
    int g[N],g1[N];
    int pos[2*N];
    int t;
    int mark[N*2];
    scanf("%d",&t);
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        memset(pos,0,sizeof(pos));
        int n,m;
        scanf("%d%d",&n,&m);
        int l=n/2;
        for(int i=1;i<=l;i++)
        {
            g[i]=i;
            mark[i]=0;////// 0 表示 下层
            pos[i]=i;// pos 表示该数在数组中的位置...
        }
        for(int i=l+1;i<=n;i++)
        {
            g1[i-l]=i;
            mark[i]=1;
            pos[i]=i-l; //
        }

        ///////////////////

        char c;
        for(int i=0;i<m;i++)
        {
            cin>>c;
            if(c=='A')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(mark[x]==0)
                    swap(g[pos[x]],g1[pos[y]]);
                else
                    swap(g1[pos[x]],g[pos[y]]);

                swap(mark[x],mark[y]);
                continue;
            }
            if(c=='B')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                if(mark[x]==0)
                {
                    swap(g[pos[x]],g[pos[y]]);
                }
                else
                    swap(g1[pos[x]],g1[pos[y]]);

                swap(pos[x],pos[y]);
                continue;
            }
            if(c=='Q')
            {
                int x;
                scanf("%d",&x);
                int t=pos[x];// 表示x  在数组中的位置....
                if(mark[x]==0)
                {
                    if(t==1)
                    {
                        printf("%d %d %d\n",g[l],g[t+1],g1[t]);
                    }
                    else
                    {
                        if(t==l)
                            printf("%d %d %d\n",g[t-1],g[1],g1[t]);
                        else
                            printf("%d %d %d\n",g[t-1],g[t+1],g1[t]);
                    }
                }
                else
                {
                    if(t==1)
                    {
                        printf("%d %d %d\n",g1[l],g1[t+1],g[t]);
                    }
                    else
                    {
                        if(t==l)
                            printf("%d %d %d\n",g1[t-1],g1[1],g[t]);
                        else
                            printf("%d %d %d\n",g1[t-1],g1[t+1],g[t]);
                    }
                }
            }
        }
    }
    return 0;
}
