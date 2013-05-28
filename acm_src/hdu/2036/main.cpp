#include <stdio.h>

double S(int x[],int y[],int n)
{
    int i,j;
    double s=0;
    for(i=0;i<n;i++){
        j=(i+1)%n;
        s+=x[i]*y[j];
        s-=x[j]*y[i];
    }
    s/=2;
    return s>0?s:-s;
}
int main()
{
    //freopen("in.dat", "r", stdin);
    int n,i;
    int x[100],y[100];
    double s;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        s=S(x,y,n);
        printf("%.1lf\n",s);
    }
    return 0;
}

