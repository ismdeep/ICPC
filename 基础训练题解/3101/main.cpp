#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int s, d;
    while(scanf("%d%d" ,&s, &d) != EOF)
    {
        int i;
        for(i = 1; i <= 5; i++)
        {
            if( s * (5-i) - d * i < 0 )
            {
                break;
            }
        }
        
        int ans;
        if(i == 4)
        {
            ans = 3 * s - 9 * d;
        }
        else
        {
            ans = s * (12-2*i) - d * 2 * i;
        }
        
        if(i == 5 || ans < 0)
        {
            printf("Deficit\n");
        }
        else
        {
            printf("%d\n",ans);
        }
        
    }
    
    return 0;
}
//end
//ism

