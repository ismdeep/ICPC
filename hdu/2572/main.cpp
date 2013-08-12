#include <stdio.h>
#include <string.h>

struct A
{
	int s;
	int e;
}a[111],b[111];
int min(int a,int b)
{
	return a>b?b:a;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	char str[111];
	char str1[22],str2[22];
	char ans[111],str_temp[111];
	int k1,k2;
	int T;
	int i,l,j,j2,temp;
	int len,len1,len2;
	int temp1,temp2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s%s",str,str1,str2);
		len=strlen(str);
		len1=strlen(str1);
		len2=strlen(str2);

		k1=k2=0;
		for(i=0;len-i>=len1;i++)
		{
			for(l=i,temp=0;temp<len1;temp++,l++)	if(str[l]!=str1[temp])	break;
			if(temp==len1)
			{
				a[k1].s=i;
				a[k1].e=l-1;
				k1++;
			}
		}
		for(i=0;len-i>=len2;i++)
		{
			for(l=i,temp=0;temp<len2;temp++,l++)	if(str[l]!=str2[temp])	break;
			if(temp==len2)
			{
				b[k2].s=i;
				b[k2].e=l-1;
				k2++;
			}
		}


		if(k1==0||k2==0)
		{
			printf("No\n");
			continue;
		}


		len=222;
		for(i=0;i<k1;i++)
		for(l=0;l<k2;l++)
			if(max(a[i].e,b[l].e)-min(a[i].s,b[l].s)<len)
				len=max(a[i].e,b[l].e)-min(a[i].s,b[l].s);


		for(i=0;i<k1;i++)
		for(l=0;l<k2;l++)
			if(max(a[i].e,b[l].e)-min(a[i].s,b[l].s)==len)
			{
				temp=max(a[i].e,b[l].e);
				for(j2=0,j=min(a[i].s,b[l].s);j<=temp;j++,j2++)	ans[j2]=str[j];
				ans[j2]=0;
				temp1=i;
				temp2=l;
			}


		for(i=0;i<k1;i++)
		for(l=0;l<k2;l++)
			if(max(a[i].e,b[l].e)-min(a[i].s,b[l].s)==len)
			{
				if(i==temp1&&l==temp2)	continue;
				temp=max(a[i].e,b[l].e);
				for(j2=0,j=min(a[i].s,b[l].s);j<=temp;j++,j2++)	str_temp[j2]=str[j];
				str_temp[j2]=0;
				if(strcmp(ans,str_temp)>0)	strcpy(ans,str_temp);
			}


		printf("%s\n",ans);
	}
	return 0;
}

