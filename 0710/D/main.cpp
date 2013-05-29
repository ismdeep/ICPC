// Project name : D ( Fibonacci ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 14:02:23 2012

#include <iostream>
#include <stdio.h>
using namespace std;


int p[30][4]={1,1,1,0};

void mm(int * ret,int * a,int * b)
{
    int x[4],y[4],i;
    for(i=0;i<4;i++)
    {
         x[i]=a[i];
         y[i]=b[i];
     }    
     ret[0] = (x[0]*y[0] + x[1]*y[2]) % 10000;
     ret[1] = (x[0]*y[1] + x[1]*y[3]) % 10000;
     ret[2] = (x[2]*y[0] + x[3]*y[2]) % 10000;
     ret[3] = (x[2]*y[1] + x[3]*y[3]) % 10000;    
}

int main()
{
    int i,n;
    int a[4]={0,1,1,0};
    for(i=1;i<30;i++)
    {
         mm(p[i],p[i-1],p[i-1]);
     }
    while(1)
    {
         scanf("%d",&n);
        if(n==-1) break;
         a[0]=1;a[1]=0;a[2]=0;a[3]=1;
        
        for(i=0;i<30;i++)
        {
            if(n&(1<<i))
            {
                 mm(a,a,p[i]);
            }
        }
		 cout << a[1] << endl;
    }

	return 0;
}


// end 
// ism 

