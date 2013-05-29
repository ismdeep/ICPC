// Project name : A ( Ignatius and the Princess IV ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 21:28:58 2012


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a[32769];
int n;
int temp;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        
        int max = 0;
        int flag = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            a[temp]++;
            if (a[temp] > max)
            {
                flag = temp;
                max  = a[temp];
            }
        }
        
        printf("%d\n", flag);
    }
    
    return 0;
}

// end 
// ism 

