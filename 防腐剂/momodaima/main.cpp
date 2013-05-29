#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
	int num[5],i;
	string str;
	while(cin>>str)
	{
		memset(num,0,sizeof(num));
		for(i=0;i < (int)str.length();i++)
		{
			if (str[i]=='d')
			{
				num[0]++;
				num[0]%=10000007;
			}
			else if(str[i]=='r')
			{
				num[1]+=num[0];
				num[1]%=10000007;
			}
			else if (str[i]=='e')
			{
				num[2]+=num[1];
				num[2]%=10000007;
			}
			else if (str[i]=='a')
			{
				num[3]+=num[2];
				num[3]%=10000007;
			}
			else
			{
				num[4]+=num[3];
				num[4]%=10000007;
			}
		}
		printf("%d\n",num[4]);
	}
	return 0;
}

