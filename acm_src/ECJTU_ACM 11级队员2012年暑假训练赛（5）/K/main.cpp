#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
double x[110],y[110],w[10010];
int u[10010],v[10010],p[110],r[10010];
int cmp(const void *_p,const void *_q)
{
    int *p=(int *)_p;
    int *q=(int *)_q;
    return w[*p]>w[*q]?1:-1;
}

int iFind(int x)
{
    return p[x]==x?x:(p[x]=iFind(p[x]));
}

double iDistance(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
    int i,j,n,e,tx,ty;
    double ans;
    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
        e=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                u[e]=i;
                v[e]=j;
                w[e]=iDistance(i,j);
                e++;
            }
        for(i=0;i<n;i++)
            p[i]=i;
        for(i=0;i<e;i++)
            r[i]=i;
        qsort(r,e,sizeof(r[0]),cmp);
        ans=0.0;
        for(i=0;i<e;i++)
        {
            tx=iFind(u[r[i]]);
            ty=iFind(v[r[i]]);
            if(tx!=ty)
            {
                p[tx]=ty;
                ans+=w[r[i]];
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
