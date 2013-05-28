//project name:2032 ( Ñî»ÔÈı½Ç )
//Author:¼üÅÌÉ±ÊÖ
//Creat Date & Time:Mon Apr 16 07:47:29 2012

#include <iostream>
using namespace std;

int main()
{
    int k;
	//int count=0;
	while(cin >> k)
	{
	    /* if(count)
		{
		    cout<<endl;
		}
		count++;
		 */
		void work(int);
		work(k);
		cout<<endl;
	}
	
    return 0;
}
////////////////////////////////////////////////
void work(int n)
{
    int a[30][30];
	
	a[0][0] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	
	for(int i = 2; i < n; i++)
	{
	    a[i][0] = 1;
		for(int j = 1; j < i; j++)
		{
		    a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
		a[i][i] = 1;
	}
	
	// output the result
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < i; j++)
		{
		    cout<<a[i][j]<<" ";
		}
		
		cout<<a[i][i]<<endl;
	}
	
	
}
//end
//ism
