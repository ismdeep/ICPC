#include <stdio.h>
#include <string.h>

#define MAX 50005

struct trea
{
    int l, r;
    int summ;
}trees[MAX*3];

int num[MAX],n,t;

void biuld(int i,int l,int r)
{
    trees[i].l=l;
    trees[i].r=r;
    if(l==r)
    {
        trees[i].summ=num[l-1];
        return ;
    }
    int mid=(l+r)/2;
    biuld(i*2,l,mid);
    biuld(i*2+1,mid+1,r);
    trees[i].summ=trees[i*2].summ+trees[i*2+1].summ;
}

void add(int i,int l,int m)
{
    trees[i].summ+=m;

    if(trees[i].l==l&&trees[i].r==l)return ;

    int mid=(trees[i].l+trees[i].r)/2;

    if(l<=mid) add(i*2,l,m);
    else add(i*2+1,l,m);
}

int query(int i,int l,int r)
{
    if(trees[i].l==l&&trees[i].r==r)
        return trees[i].summ;
    else
    {
        int mid=(trees[i].l+trees[i].r)/2;

        if(l>mid)return query(i*2+1,l,r);
        else if(r<=mid)return query(i*2,l,r);
        else return query(i*2,l,mid)+query(i*2+1,mid+1,r);
    }
}


int main()
{
    char str[10];

    int k=0,i;

    int a,b;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)scanf("%d",&num[i]);

        //for(i=0;i<n;i++)printf("%d\n",num[i]);

        biuld(1,1,n);

        printf("Case %d:\n",++k);

        while(scanf("%s",str))
        {
            if(strcmp(str,"End")==0)
                break;
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Add")==0)add(1,a,b);
            else if(strcmp(str,"Sub")==0)add(1,a,-b);
            else
            {
                printf("%d\n",query(1,a,b));
            }
        }
    }

    return 0;
}
