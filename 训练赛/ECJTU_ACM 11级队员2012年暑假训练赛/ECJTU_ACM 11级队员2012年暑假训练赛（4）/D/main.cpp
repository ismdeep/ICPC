#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 20
#define MAXM 1010
#define INF  9999999

int n,m;
int head[MAXN],num,src,des,level[MAXN];

struct node{
     int from,to,next;
    int flow;
}edge[2*MAXM];

void addedge(int u,int v,int flow)
{
    edge[num].from=u;
    edge[num].to=v;
    edge[num].flow=flow;
    edge[num].next=head[u];
    head[u]=num++;

    edge[num].from=v;
    edge[num].to=u;
    edge[num].flow=0;
    edge[num].next=head[v];
    head[v]=num++;
}

bool dinic_bfs()
{
34     int i,j,que[MAXN],rear;
35     memset(level,-1,sizeof(level));
36     rear=0;
37     que[rear++]=src;
38     level[src]=0;
39     for(i=0;i<rear;i++)
40         for(j=head[que[i]];j!=-1;j=edge[j].next)
41             if(edge[j].flow>0 && level[edge[j].to]==-1)
42             {
43                 level[edge[j].to]=level[que[i]]+1;
44                 que[rear++]=edge[j].to;
45             }
46    return level[des]>=0;
47 }
48
49 int dinic_dfs(int t,int cp)
50 {
51     if(t==des)
52         return cp;
53     int j,temp,res=0;
54     for(j=head[t];j!=-1;j=edge[j].next)
55     {
56         if(level[edge[j].to]==level[t]+1 && edge[j].flow>0)
57         {
58             temp=dinic_dfs(edge[j].to,edge[j].flow<cp?edge[j].flow:cp);
59             if(temp)
60             {
61                 edge[j].flow-=temp;
62                 edge[j^1].flow+=temp;
63                 return temp;
64             }
65         }
66     }
67     return 0;
68 }
69
int dinic()
{
     int temp,res=0;
    while(dinic_bfs())
        if(temp=dinic_dfs(src,INF))
            res+=temp;
    return res;
}

void main()
 {
     int i,j,cas,u,v,flow;
     cin>>cas;
     for(j=1;j<=cas;j++)
     {
         cin>>n>>m;
         num=0;
         memset(head,-1,sizeof(head));
         src=1;
         des=n;
         for(i=1;i<=m;i++)
         {
             cin>>u>>v>>flow;
             addedge(u,v,flow);
         }
         cout<<"Case "<<j<<": "<<dinic()<<endl;
     }
}
