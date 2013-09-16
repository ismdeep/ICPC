#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;
#define INF 0x3fffffff

int save[100100];
char g[20][20]={{" "},{" "},{"ab"},{"aab"},{"aabb"},{"aaaba"},{"aaabab"},{"aaababb"}
,{"aaababbb"}
,{"aaaababba"}
,{"aaaababbaa"}
,{"aaaababbaaa"}
,{"aaaababbaaaa"}};

char k[10]={"babbaa"};

int main()
{
    //freopen("C:\\Users\\chen\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\chen\\Desktop\\in.txt","w",stdout);
    int T;
    int tt=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",tt++);
        if(m>=3)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                printf("%c",cnt+'a');
                cnt++;
                if(cnt==3) cnt=0;
            }
        }
        else if(m==1)
        {
            for(int i=0;i<n;i++)
                printf("a");
        }
        else
        {
            if(n<=12)
                printf("%s",g[n]);
            else
            {
                printf("aaaa");
                n-=4;
                int tmp=n/6;
                for(int i=0;i<tmp;i++)
                    printf("babbaa");
                n=n-tmp*6;
                if(n==1)
                    printf("a");
                else if(n==2) printf("aa");
                else
                {
                    for(int ii=0;ii<n;ii++)
                        printf("%c",k[ii]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
