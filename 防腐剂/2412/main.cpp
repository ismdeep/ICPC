#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int map[51][51][4],n,m;

void dfs(int i,int j)
{
	if(map[i][j][0])
	{
		map[i][j][0]=0;
		if(map[i][j+1][3])
		{
			dfs(i,j+1);
		}
	}
	if(map[i][j][1])
	{
		map[i][j][1]=0;
		if(map[i-1][j][2])
		{
			dfs(i-1,j);
		}
	}
	if(map[i][j][2])
	{
		map[i][j][2]=0;
		if(map[i+1][j][1])
		{
			dfs(i+1,j);
		}
	}
	if(map[i][j][3])
	{
		map[i][j][3]=0;
		if(map[i][j-1][0])
		{
			dfs(i,j-1);
		}
	}
}

int main()
{
	int i,j;
	char ch[51];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		if(n<0&&m<0) break;
		for(i=0;i<n;i++)
		{
			scanf("%s",ch);
			for(j=0;j<m;j++)
			{
				if(ch[j]=='B'||ch[j]=='D'||ch[j]=='F'||ch[j]=='G'||ch[j]=='I'||ch[j]=='J'||ch[j]=='K')
				{
					map[i][j][0]=1;
				}
				if(ch[j]=='A'||ch[j]=='B'||ch[j]=='E'||ch[j]=='G'||ch[j]=='H'||ch[j]=='J'||ch[j]=='K')
				{
					map[i][j][1]=1;
				}
				if(ch[j]=='C'||ch[j]=='D'||ch[j]=='E'||ch[j]=='H'||ch[j]=='I'||ch[j]=='J'||ch[j]=='K')
				{
					map[i][j][2]=1;
				}
				if(ch[j]=='A'||ch[j]=='C'||ch[j]=='F'||ch[j]=='G'||ch[j]=='H'||ch[j]=='I'||ch[j]=='K')
				{
					map[i][j][3]=1;
				}
			}
		}
		int num=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(map[i][j][0]||map[i][j][1]||map[i][j][2]||map[i][j][3])
				{
					dfs(i,j);
					num++;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}

