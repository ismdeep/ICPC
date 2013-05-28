#include <stdio.h>
#include <string.h>
#define INF 100000000
int main()
{
	int t,n,i;
	int hb,mb,sb;
	int he,me,se;
	int first,end;
	char name[2][200],namec[200];
	scanf("%d",&t);
	while(t--)
	{
	     scanf("%d%*c",&n);
	     first=INF;
	     end=0;
	     for(i=0;i<n;i++)
	     {
	           scanf("%s%d%*c%d%*c%d%d%*c%d%*c%d%*c",namec,&hb,&mb,&sb,&he,&me,&se);
	           if(first>(hb*3600+mb*60+sb)){
	              first=hb*3600+mb*60+sb;
	              strcpy(name[0],namec);
	            }
	            if(end<(he*3600+me*60+se)){
	                end=he*3600+me*60+se;
	                strcpy(name[1],namec);
	            }
	      }
	      printf("%s %s\n",name[0],name[1]);
	 }
	 return 0;
}


