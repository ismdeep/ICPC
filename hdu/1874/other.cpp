#include <iostream>
#include <stdio.h>
using namespace std;

const int SIZE=201;
const int INF=99999999;

int G[SIZE][SIZE],dis[SIZE],N,M;
bool vis[SIZE];

int Dijkstra(int s,int t){
	int i,k;
	
	for(i=0;i<N;++i){
		vis[i]=0;
		dis[i]=G[s][i];
	}
	vis[s]=1; dis[s]=0;
	
	for(k=0;k<N-1;++k){
		int min_i,min=INF;
		for(i=0;i<N;++i)
			if(!vis[i] && dis[i]<min)
				min=dis[min_i=i];
		if(min==INF)
			break;
		vis[min_i]=1;
		
		for(i=0;i<N;++i)
			if(!vis[i] && dis[min_i]+G[min_i][i]<dis[i])
				dis[i]=dis[min_i]+G[min_i][i];
	}
	
	return dis[t]==INF?-1:dis[t];
}

int main()
{
	int i,j,s,t;
	
	while(~scanf("%d %d",&N,&M)){
		for(i=0;i<N;++i){
			for(j=0;j<N;++j)
				G[i][j]=INF;
		}
		
		int u,v,w;
		for(i=0;i<M;++i){
			scanf("%d %d %d",&u,&v,&w);
			if(w<G[u][v])
				G[u][v]=G[v][u]=w;
		}
		scanf("%d %d",&s,&t);
		
		printf("%d\n",Dijkstra(s,t));
	}
	
	return 0;
}

// end 
// ism 

