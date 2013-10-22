#include <iostream>
#include <cstring>
using namespace std;

#define N 10

int n,m,t,end_i,end_j;
bool visited[N][N],flag,ans;
char map[N][N];

int abs(int a, int b)
{
    return (a>b)?a-b:b-a;
}

void DFS(int i, int j, int c)
{
    if( flag )
    {
        return;
    }
    if( c > t )
    {
        return;
    }
    if( i < 0 || i >= n || j < 0 || j >= m ) // 该点非法
    {
        return;
    }
    if(map[i][j]=='D'&&c==t)
    {
        flag=ans=true;
        return ;
    }
    int temp = abs(i , end_i) + abs(j , end_j);
    temp = t - temp - c;
    
    if( temp & 1 ) // 奇偶剪枝
    {
        return ;
    }
    
    // start search
    if(!visited[i-1][j] && map[i-1][j] != 'X')
    {
        visited[i-1][j]=true;
        DFS(i-1,j,c+1);
        visited[i-1][j]=false;
    }
    
    if(!visited[i+1][j] && map[i+1][j] != 'X')
    {
        visited[i+1][j]=true;
        DFS(i+1,j,c+1);
        visited[i+1][j]=false;
    }
    
    if(!visited[i][j-1] && map[i][j-1] != 'X')
    {
        visited[i][j-1]=true;
        DFS(i,j-1,c+1);
        visited[i][j-1]=false;
    }
    
    if(!visited[i][j+1] && map[i][j+1] != 'X')
    {
        visited[i][j+1]=true;
        DFS(i,j+1,c+1);
        visited[i][j+1]=false;
    }
    
    
}


int main()
{
    while( cin >> m >> n >> t && m+n+t )
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                visited[i][j] = false;
            }
        }
        
        int k = 0;
        int x,y;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 'S')
                {
                    x = i;
                    y = j;
                    visited[i][j] = true;
                }
                
                if(map[i][j] == 'D')
                {
                    end_i = i;
                    end_j = j;
                }
                
                if(map[i][j] == 'X')
                {
                    k++;
                }
                
                
            }
        }
        
        ans = flag = false;
        if(n*m-k-1 >= t)
        {
            DFS(x, y, 0);
        }
        
        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
}
//end
//ism

