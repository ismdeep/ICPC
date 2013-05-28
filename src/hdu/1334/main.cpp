#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    for(int i = 6; i <= 200; i++)
    {
        for(int j = 2; j < i; j++)
        {
            for(int k = j; k < i; k++)
            {
                for(int t = k; t < i; t++)
                {
                    if(i*i*i == j*j*j + k*k*k + t*t*t)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,t);
                    }
                }
            }
        }
    }
    
    return 0;
}

// end 
// ism 

