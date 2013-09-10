//File name:main.cpp
//Author:键盘杀手
//Creat Date & Time:Sat May  5 20:18:08 2012

#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1005

int a[MAX];
int pre[MAX];

int main()
{
    
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        
        sort(a+1, a+1+n);
        a[0] = 0;
        //pre[0] = a[0];
        pre[0] = 0;
        for(int i = 0; i <= n; i++)
        {
            pre[i] = pre[i-1] + a[i];
        }
        
        int i;
        for(i = 1; i <= n; i++)
        {
            if(a[i] > (pre[i-1]+1))
            {
                break;
            }
        }
        
        printf("%d\n",pre[i-1]+1);
        
    }
    
    return 0;
}
//end
//ism
