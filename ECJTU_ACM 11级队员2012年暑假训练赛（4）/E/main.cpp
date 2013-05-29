#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1<<30;


int g[1100][1100];
int d[1100];
int used[1100];
int flag[1010];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = INF;
        }
    }
    memset(used, 0, sizeof(used));
}

void F(int star, int n)
{
    d[star] = 0;
    int min, min_num;

    for (int cnt = 0; cnt < n; cnt++)
    {
        min = INF;
        for (int i = 0; i < n; i++)
        {
            if (!used[i] && min > d[i])
            {
                min     = d[i];
                min_num = i;
            }
        }

        used[min_num] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!used[i] && d[i] > d[min_num] + g[min_num][i])
            {
                d[i] = d[min_num] + g[min_num][i];
            }
        }
    }
}

int main()
{
    int m, s, d1;
    while (cin >>m >> s >> d1)
    {
        init(1001);
        while (m--)
        {
            int a, b, c;
            cin >> a >> b>>c;
            if (c < g[a][b])
            {
                g[a][b] = g[b][a] = c;
            }
        }
        while (s--)
        {
            int a;
            cin >> a;
            g[0][a] = g[a][0] = 0;
        }
        int k = 0;
        while (d1--)
        {
            int a;
            cin >> a;
            flag[k++] = a;
        }

        F(0, 1001);

        int min = INF;
        for (int i = 0; i < k; i++)
        {
            if (min > d[flag[i]])
            {
                min = d[flag[i]];
            }
        }
        cout << min << endl;
    }
    return 0;
}

// end
// ism

