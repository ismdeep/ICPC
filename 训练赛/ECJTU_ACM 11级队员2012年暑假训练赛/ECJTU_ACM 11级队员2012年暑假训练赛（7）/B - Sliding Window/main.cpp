#include <cstdio>
using namespace std;

int iMap[1000005] ;
int queue[1000005] ;
int n, k ;

void iGetMin()
{
    int h, r ;
    h = r = 0 ;
    queue[0] = 0 ;
    for(int i=0; i<n; i++)
    {
        if(i-queue[h]==k)   h ++ ;
        if(r==h-1||iMap[i]>iMap[queue[r]])
        {
            r ++ ;
            queue[r] = i ;
        }
        else
        {
            while(r>=h&&iMap[i]<=iMap[queue[r]])
            {
                queue[r] = i ;
                r -- ;
            }
            r ++ ;
        }
        if(i>=k-1)
        {
            printf("%d ", iMap[queue[h]]);
        }
    }
    printf("\n") ;
}
void iGetMax()
{
    int h, r ;
    h = r = 0 ;
    queue[0] = 0 ;
    for(int i=0; i<n; i++)
    {
        if(i-queue[h] == k)   h ++ ;
        if(r == h-1 || iMap[i] < iMap[queue[r]])
        {
            r++ ;
            queue[r] = i ;
        }
        else
        {
            while(r>=h&&iMap[i]>=iMap[queue[r]])
            {
                queue[r] = i ;
                r -- ;
            }
            r ++ ;
        }
        if(i>=k-1)
        {
            printf("%d ", iMap[queue[h]]);
        }
    }
    printf("\n") ;
}

int main()
{
    //freopen("in.dat", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &iMap[i]);
        }
        iGetMin();
        iGetMax();
    }
    return 0;
}
