#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAXN 500022
int sum[MAXN];

void makeprime()
{
    int i,j;
    for(i=1;i<MAXN;i++)sum[i] =1;
    sum[0] = 0 ;
    for(i=2;i<MAXN/2;i++)
    {
        for(j=2*i;j<MAXN;j+=i)
        {
            sum[j] += i;
        }
    }
}

int main()
{
    int T,n;
    makeprime();

    while(cin >> T)
    {
        while(T--)
        {
            scanf("%d",&n);
            printf("%d\n",sum[n]);
        }
    }
    return 0 ;
}


// end
// ism

