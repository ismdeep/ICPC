// Project name : D ( Kindergarten Counting Game ) 
// File name    : main.cpp
// Author       : Izumu
// Date & Time  : Tue Jul 10 19:40:52 2012


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 10000

char a[N];

int main()
{
	int n;
	
	while(gets(a)!=NULL)
	{
		n=strlen(a);
		int found,count=0;
		for(int i=0;i<n;i++)
		{	
			if(isalpha(a[i])) found=1;
			else{
				if(found) count++; 
				found =0;
			}
			
			
		}
		printf("%d\n",count);
		
	}
	return 0;
}


// end 
// ism 

