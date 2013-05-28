#include <stdio.h>
using namespace std;

int data[1000010];
struct tnode
{
    int left, right;
    int min,max;
}t[1000010*4];
struct out
{
    int min,max;
}dataout[1000010];
void creat(int st,int ed,int r)
{
    int mid;
    t[r].left=st;
    t[r].right=ed;
    if(st==ed)
    {
        t[r].min=t[r].max=data[st];
        return ;
    }
    mid=(st+ed)>>1;
    creat(st,mid,r*2);
    creat(mid+1,ed,r*2+1);

    t[r].min=t[r*2].min;
    if(t[r].min>t[r*2+1].min)
        t[r].min=t[r*2+1].min;
    t[r].max=t[r*2].max;
    if(t[r].max<t[r*2+1].max)
        t[r].max=t[r*2+1].max;
}
void search(int st,int ed,int & min,int & max,int r=1)
{
    int mid;
    int min2,max2;
    if(st==t[r].left&&ed==t[r].right)
    {
        min=t[r].min;
        max=t[r].max;
        return ;
    }
    mid=(t[r].left+t[r].right)>>1;
    if(mid>=ed)
        search(st,ed,min,max,r*2);
    else if(mid<st)
        search(st,ed,min,max,r*2+1);
    else
    {
        search(st,mid,min,max,r*2);
        search(mid+1,ed,min2,max2,r*2+1);
        if(min>min2)
            min=min2;
        if(max<max2)
            max=max2;
    }
}
int main()
{
    //freopen("in.dat", "r", stdin);
    int i,n,k;
    scanf("%d%d", &n, &k);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &data[i]);
    }
    creat(1,n,1);
    for(i=1;i<=n-k+1;i++)
    {
        search(i,i+k-1,dataout[i].min,dataout[i].max,1);
    }
    printf("%d",dataout[1].min);
    for(i=2;i<=n-k+1;i++)
        printf(" %d",dataout[i].min);
    printf("\n");

    printf("%d",dataout[1].max);
    for(i=2;i<=n-k+1;i++)
        printf(" %d",dataout[i].max);
    printf("\n");
    return 0;
}


// end
// iCoding@CodeLab
