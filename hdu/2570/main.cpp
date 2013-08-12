#include <cstdio>
#include <cstdlib>
#include <cstring>
int cmp(const void*a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    //freopen("d.txt","r",stdin);
    int n,t,v,w,a[107],sum,V,i;
    scanf("%d",&t);
    while(t--)
    {
        sum=V=0;
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&v,&w);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0;i<n;i++)
        {
           if(1.0*(sum+a[i])/(V+1)<=(w*1.0))
           {
               sum+=a[i];
               V+=1;
           }
           else
           break;
        }
        if(sum==0)
        printf("0 0.00\n");
        else
        printf("%d %.2lf\n",V*v,0.01*sum/V);
    }
    return 0;
}

// end
// ism
