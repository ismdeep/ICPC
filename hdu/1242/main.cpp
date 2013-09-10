#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 205;

typedef struct node
{
    int x, y;
    int step;
    node(int a = 0) : step(a){};
    friend bool operator < (const struct node &n1, const struct node &n2)
    {
        return n1.step > n2.step;
    }
}N;

int n, m, ex, ey;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

void init()
{
    memset(visited, false, sizeof(visited));
}

int BFS(int x, int y)
{
    priority_queue<N> Q;
    N pre, cur;
    pre.x = x,pre.y = y;
    pre.step = 0;
    Q.push(pre);
    visited[pre.x][pre.y] = true;
    while (!Q.empty())
    {
        pre = Q.top();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            cur = pre;
            cur.x += dir[i][0];
            cur.y += dir[i][1];
            cur.step++;

            if (visited[cur.x][cur.y] == false && cur.x >= 1 && cur.x <= n && cur.y >= 1
                && cur.y <= m && map[cur.x][cur.y] != '#')
            {
                if (map[cur.x][cur.y] == 'r')
                {
                    return cur.step;
                }
                if (map[cur.x][cur.y] == 'x')
                {
                    cur.step++;
                }
                visited[cur.x][cur.y] = true;
                Q.push(cur);
            }
        }
    }
    return -1; // not found
}

/* main */
int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        init();
        int i, j, flag = 1;
        for (i = 1; i <= n; i++)
        {
            scanf("%s", map[i] + 1);
            for (j = 1; j <= m; j++)
            {
                if (map[i][j] == 'a')
                {
                    ex = i;
                    ey = j;
                }
                if (map[i][j] == 'r')
                {
                    flag = 0;
                }
            }
        }

        int ans = BFS(ex, ey);
        if (ans == -1 || flag == 1)
        {
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}

// end
// ism
