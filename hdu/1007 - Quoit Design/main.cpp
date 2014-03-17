#include <iostream>
#include <stdio.h>
using namespace std;

#define N 100000

typedef struct Point
{
    float x, y;
}Point;


Point p[N];

bool cmp_point (Point pa, Point pb)
{
    return pa.x < pb.x;
}


int n;

int main()
{
    #ifdef _ISM_DEBUG_
        freopen ("in.txt", "r", stdin);
    #endif // _ISM_DEBUG_
    while (cin >> n,n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << endl;
        }
    }
    return 0;
}
