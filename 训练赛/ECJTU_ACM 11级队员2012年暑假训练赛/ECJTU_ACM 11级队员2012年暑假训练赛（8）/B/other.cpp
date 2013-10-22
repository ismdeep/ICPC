#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1005
using namespace std;

bool visit[MAXN];

int main()
{
    int cas, a, m, k, t;
    scanf("%d", &cas);
    while ( cas-- )
    {
        memset( visit, false, sizeof( visit ) );
        scanf("%d %d", &a, &m);
        for( k = 0; ; ++k )
        {
            t = ( k * m + 1 ) % a;
            if( ( k * m + 1 ) % a == 0 )
            {
                printf("%d\n", ( k * m + 1 ) / a);
                break;
            }
            if( visit[t] ) break;
            visit[t] = true;
        }
        if( visit[t] ) puts("Not Exist");
    }
    return 0;
}


