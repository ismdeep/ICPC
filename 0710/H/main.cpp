// Project name : H
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 13:30:13 2012

#include<stdio.h>
#include<string.h>

#define Max 1000001





int main()
{
    int n, m, a, b, c, i, j, min;
    int map[102][102];
    int dist[102];
    int v;
    int flag[102];
    while(scanf("%d %d", &n, &m) !=EOF && n + m)
    {
       memset(flag, 0, sizeof(flag));
       for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
         map[i][j]=Max;
       
	   for(i = 1; i <= m; i++)
       {
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
        flag[a]=flag[b]=1;
       }
       flag[1]=0;
       for(i=1;i<=n;i++)
        dist[i]=map[1][i];
       for(i=1;i<n;i++)//要找n-1次
       {
        min=Max;
        for(j=1;j<=n;j++)
        {
         if(flag[j]==1 && min>dist[j])
         {
          v=j;
          min=dist[j];
         }
        }
        flag[v]=0;
        for(j=1;j<=n;j++)
        {
         if(flag[j]==1 && map[v][j]+dist[v]<dist[j])
          dist[j]=map[v][j]+dist[v];
        }
       
       }
       printf("%d\n",dist[n]);
    }
    return 0;
}


// end 
// ism 

