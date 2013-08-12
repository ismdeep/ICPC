//project file: 1397 (Goldbach's Conjecture)
//file name: main.cpp 
//author:键盘杀手
//date & time: 2012 5 4 -> 22:21
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

bool prime[32768];

void initPrime()
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;
    prime[3] = true;
    prime[4] = false;
    prime[5] = true;
    
    for(int i = 6; i < 32768; i++)
    {
        bool yes = true;
        int stop = sqrt(i);
        for(int j = 2; yes && j <= stop; j++)
        {
            if(i%j == 0)
            {
                yes = false;
            }
        }
        prime[i] = yes;
    }
}

int main()
{
    int n;
    initPrime();
    while( scanf("%d",&n) && n )
    {
        int stop = n / 2;
        int count = 0;
        for(int i = 2; i <= stop; i++ )
        {
            if( prime[i] && prime[n-i] )
            {
                count++;
            }
        }
        
        printf("%d\n",count);
    }
    
    return 0;
}
//end
//ism

