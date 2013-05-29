// Project name : E
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 15:13:33 2012

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=222;
int c[maxn][maxn];
int f[maxn][maxn];
bool you[maxn][maxn];
int cen[maxn];
int n,m;
int tx,ty,tc;
vector<int>g[maxn];
queue<int>q;
bool bfs()
{
    memset(cen,-1,sizeof(cen));
    while (!q.empty()) q.pop();
    q.push(1);
    cen[1]=0;   
    int now;
    while(!q.empty()) 
    {
        now=q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++)
        {
            if(you[now][g[now][i]] && cen[g[now][i]] == -1)
            {   
                cen[g[now][i]]= cen[now] + 1;
                q.push(g[now][i]);
            }
        }    
    }  
    return cen[n]!=-1; 
}
int dfs(int flow=inf,int now=1)
{
    if(cen[now] == cen[n] )
    {       
        if(now == n)
        {
            return flow;
        }
        else
        {   
            return 0;
        }
    }
    int temp,sum;
    sum = 0;
    for(int i=0;i<g[now].size();i++)
    {
        if(cen[g[now][i]] - cen[now]  !=1 || !you[now][g[now][i]] || cen[g[now][i]] > cen[n] )
        {
            continue;
        }
        temp = dfs (min(c[now][g[now][i]] - f[now][g[now][i]] , flow) , g[now][i]);        
        f[now][g[now][i]] += temp;
        f[g[now][i]][now] -= temp;
        if(f[now][g[now][i]] == c[now][g[now][i]]) 
        {
            you[now][g[now][i]] = false;
        }            
        you[g[now][i]][now] = true;
        sum += temp;
        flow -= temp;
    }            
    return sum;
}

int dinic()
{
    int ans=0;
    while( bfs() )
    {
        ans+=dfs();    
    }      
    return ans;
}

int main()
{
    while(cin>>m>>n)
    {                           
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        memset(you,false,sizeof(you));
        for(int i=1;i<=n;i++)
        {   
            g[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            cin>>tx>>ty>>tc;
            c[tx][ty]+=tc;
            you[tx][ty]=true;
            g[tx].push_back(ty);
            g[ty].push_back(tx);
        }
        cout<<dinic()<<endl;       
    }   
    return 0; 
}

// end 
// ism 

