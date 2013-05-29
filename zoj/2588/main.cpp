// Project name : 2588 ( Burning Bridges ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Sun Jul  8 16:13:33 2012

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

vector<int>a[10001];
vector<int>cnt[10001];
int n, m;
int f[100001];
int flag[100001];
int d[100001];
int cn[100001];
int an[100010];

struct node
{
     int x, y;
}c[100001];

void Init()
{
     int i, x, y, ok, t, j;
     scanf( "%d %d", &n, &m );
     for( i = 1; i <= n; i++ )
     {
         a[i].clear();
         cnt[i].clear();
     }
     memset( cn, 0, sizeof( cn ) );
     for( i = 1; i <= m; i++ )
     {
         f[i] = 0;
         scanf( "%d %d", &x, &y );
         c[i].x = x;
         c[i].y = y;
         ok = 0;
         for( j = 0; j < a[x].size(); j++ )
         {
             if( a[x][j] == y )
             {
                 ok = 1;
                 t = cnt[x][j];
                 break;
             }
         }
        
         if( ok == 1 )
         {
             cn[t] = 1;
             cn[i] = 1;
         }
         else
         {
             a[x].push_back(y);
             a[y].push_back(x);
             cnt[x].push_back(i);
             cnt[y].push_back(i);
         }
     }
}

void DFS( int k, int parent, int deep )
{
     int i;
     flag[k] = 1;
     d[k] = deep;
     an[k] = deep;
     for( i = 0; i < a[k].size(); i++ )
     {
         if( a[k][i] != parent && flag[a[k][i]] == 1 )an[k] = an[k] < d[a[k][i]] ? an[k] : d[a[k][i]];
         if( flag[a[k][i]] == 0 )
         {
             DFS( a[k][i], k, deep+1);
             an[k] = an[k] < an[a[k][i]] ? an[k]:an[a[k][i]];
             if( an[a[k][i]] > d[k] )f[cnt[k][i]] = 1;
         }
     }
     flag[k] = 2;
}


void Solve()
{
     int i, z[100001], top = 0;
     memset( flag, 0, sizeof( flag ) );
     DFS( c[1].x, -1, 0 );
     for( i = 1; i <= m; i++ )if( f[i] == 1 && cn[i] == 0 )z[top++] = i;
     printf( "%d\n", top );
     if( top > 0 )printf( "%d", z[0] );
     for( i = 1; i < top; i++ )printf( " %d", z[i] );
     if( top > 0 )printf( "\n" );
}

int main()
{
     int t;
     scanf( "%d", &t );
     while( t-- )
     {
         Init();
         Solve();
         if( t > 0 )printf( "\n" );
     }
     return 0;
}

// end 
// ism 

