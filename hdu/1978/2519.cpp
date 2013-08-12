// 2519.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int jc2(int x,int y)
{
	int sum=1,i;
	for(i=x;i>=y;i--)
	{
		sum = sum * i;
	}
	return sum;
}

int jc1(int x)
{
	int sum=1,i;
	for(i=1;i<x+1;i++)
		sum=sum*i;
	return sum;
}

int main()
{
	int t,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n==m||m==0)
			printf("1\n");
		else if(n<m)
			printf("0\n");
		else
		{
			n=jc2(n,m);
			m=jc1(m);
			i=n/m;
			printf("%d\n",i);
		}
	}
	//
	return 0;
	//
}

// end 
// iCoding
//

