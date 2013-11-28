//project name:1425 ( sort )
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Sat Apr 28 18:53:18 2012
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define MAXN 1000000+10
#define N 500000
using namespace std;

bool hash[MAXN];

int main(void)
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(hash,0,sizeof(hash));
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			hash[a+N]=true;
		}
		int total=0;
		for(int i=MAXN;i>=1;i--)
		{
			if(hash[i]==true)
			{
				total++;
				if(total==m)
				{
					printf("%d\n",i-N);
					break;
				}
				else printf("%d ",i-N);
			}
		}
	}
}
//end
//ism
