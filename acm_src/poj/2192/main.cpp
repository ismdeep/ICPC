// Project name : 2192
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Wed Jul 18 11:27:36 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 210

char a[MAX], b[MAX], c[2*MAX];

int dp[MAX][MAX];

int main()
{
    int i, j, t, cas;
    scanf("%d", &cas);
    for(t = 1; t <= cas; t++)
    {
        scanf("%s%s%s", a, b, c);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int la, lb;
        la = strlen(a);
        lb = strlen(b);
        for(i = 0; i <= la; i++)
        {
            for(j = 0; j <= lb; j++)
            {
                if(i > 0 && a[i-1] == c[i+j-1] && dp[i-1][j])
                    dp[i][j] = 1;
                if(j > 0 && b[j-1] == c[i+j-1] && dp[i][j-1])
                    dp[i][j] = 1;    
            }
        }

        // output for test
        for (int i = 0; i <= la; i++)
        {
            for (int j = 0; j <= lb; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        printf("Data set %d: ", t);
        if(dp[la][lb])
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}


// end 
// ism 

