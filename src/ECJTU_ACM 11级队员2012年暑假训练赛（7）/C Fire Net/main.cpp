#include <iostream>
using namespace std;


#define N 5

int map[N][N], ans, m, n;
bool visited[N][N], flag;

void dfs(int s)
{
    if(s==n*n)
    {
        if(ans<m) ans=m;
        return ;
    }
    int i,j,k;
    i=s/n;j=s%n;
    if(!visited[i][j])
    {
        flag=false;
        if(map[i][j]) flag=true;
        for(k=i-1;k>=0&&!flag;k--)
        {
            if(map[k][j]==1) break;
            if(visited[k][j]==true)
            {
                flag=true;
                break;
            }
        }
        for(k=j-1;k>=0&&!flag;k--)
        {
            if(map[i][k]==1) break;
            if(visited[i][k]==true)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            m++;
            visited[i][j]=true;
            dfs(s+1);
            m--;
            visited[i][j]=false;
            dfs(s+1);
        }
        else
        {
            dfs(s+1);
        }
    }
}


int main()
{
    int i, j;
    char t;
    while (cin >> n && n)
    {
        ans = m = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> t;
                map[i][j] = (t == 'X');
                visited[i][j] = false;
            }
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}

// end
// ism
