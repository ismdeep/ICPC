#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int g[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf ("iData[%d] = ", n);
		n++;
		int by=2014;
		int dd=3;
		for(int i=2014;i>n;i--)
		{
			if(((i-1)%4==0&&(i-1)%100!=0 )|| (i-1)%400==0 )
			{
				dd-=2;
			}
			else
				dd-=1;
			if(dd==0)
				dd=7;
			if(dd==-1)
				dd=6;
			if(dd==-2)
				dd=5;
		}
		//n++;
		//dd=2;
		dd--;
		// 就可以找到xinqi
		 // 从0开始
		int sum=0;
		while(n<2013)
		{
			if((n%4==0&&n%100!=0)||n%400==0)
			{
				g[2]=29;
			}
			for(int i=1;i<=12;i++)
			{	
				for(int j=1;j<=g[i];j++)
				{
					dd++;
					if(dd==8) dd=1;
					if(j==30 && dd==6)
						sum++;
				}
			}
			g[2]=28;
			n++;
		}
		printf("%d;\n", sum);
	}
	return 0;
}


