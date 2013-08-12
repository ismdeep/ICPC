#include <stdio.h>
#include <string.h>
#define iMin 0xfffffff

int adj[1005][1005], visit[1005], tax[1005][1005], pay[1005], low[1005];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n + m)
    {
        memset(adj, -1, sizeof(adj));
        for (int i = 1; i <= m; i++)
        {
            int a, b, d, p;
            scanf("%d%d%d%d", &a, &b, &d, &p);
            if (adj[a][b] == -1 || adj[a][b] > d)
            {
                adj[a][b] = d;
                adj[b][a] = d;
                tax[a][b] = p;
                tax[b][a] = p;
            }

        }
        int s, t;
        scanf("%d%d", &s, &t);
        for (int i = 0; i <= n; i++)
        {
            visit[i] = 0;
            low[i]   = iMin;
            pay[i]   = -1;
        }
        int index = s;
        low[s]    = 0;
        pay[s]    = 0;
        while (index != t)
        {
            int index1;
            visit[index] = 1;
            int min = iMin;
            for (int i = 1; i <= n; i++)
            {
                if (visit[i] == 1)
                {
                    continue;
                }
                if (adj[i][index] == -1 && low[i] == iMin)
                {
                    continue;
                }
                if (adj[i][index] != -1)
                {
                    if (adj[i][index] + low[index] < low[i] || low[i] == iMin)
                    {
                        low[i] = low[index] + adj[i][index];
                        pay[i] = pay[index] + tax[i][index];
                    }
                    else if (adj[i][index] + low[index] == low[i] && pay[i] > pay[index] + tax[i][index])
                    {
                        pay[i] = pay[index] + tax[i][index];
                    }
                }
                if (low[i] < min)
                {
                    min    = low[i];
                    index1 = i;
                }
                else if (low[i] == min && pay[index1])
                {
                    min    = low[i];
                    index1 = i;
                }
            }
            index = index1;
        }
        printf("%d %d\n", low[t], pay[t]);
    }
    return 0;
}
