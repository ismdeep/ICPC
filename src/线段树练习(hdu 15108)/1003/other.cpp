#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long int longint;

const int N=100100,maxn=100000;
int ccnt[N];
longint csum[N];
int lowbit(int x)
{
    return x&(x^(x-1));
}
int main()
{
    int n,x;
    while (~scanf("%d",&n))
    {
        memset(ccnt,0,sizeof(ccnt));
        memset(csum,0,sizeof(csum));
        int scnt=0;
        longint ssum=0,ans=0;
        while (n--)
        {
            scanf("%d",&x);
            scnt++; ssum+=x;
            for(int i=x;i<=maxn;i+=lowbit(i))
                ccnt[i]++, csum[i]+=x;
            int cnt=0;
            longint sum=0;
            for(int i=x;i>0;i-=lowbit(i))
                cnt+=ccnt[i], sum+=csum[i];
            ans+=ssum-sum+(longint)x*(scnt-cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
