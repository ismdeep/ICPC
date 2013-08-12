//project name:2091 ( 空心三角形 )
//Author:键盘杀手
//Creat Date & Time:Sat Apr 21 21:22:43 2012

#include <iostream>
#include <cmath>
using namespace std;

char map[41][83];

int main()
{
    
	char ch;
	int n;
	int count = 0;
	while( cin >> ch && ch != '@')
	{
	    cin >> n;
		
		if(count)
		{
		    cout << endl;
		}
		count++;
		void Make(char c,int k);
		Make(ch, n);
	}
	
    return 0;
}
/////////////////////////////////////////////////////////////
void Make(char ch, int k)
{
    for(int i = 0; i < k; i++)
	{
	    for(int j = 0; j < (2*k-1); j++)
		{
		    map[i][j] = 32;
		}
	}
	
	for(int j = 0; j <(2*k-1); j++)
	{
	    map[k-1][j] = ch;
		if(k-j-1 > 0)
		{
		    map[k-1-j][j] = ch;
		}
		else
		{
		    map[1+j-k][j] = ch;
		}
		//map[fabs(k-1-j)][j] = ch;
	}
	
	
	// output map
	for(int i = 0; i < k; i++)
	{
	    for(int j = 0; j < (k + i -1); j++)
		{
		    cout << map[i][j] ;
		}
		cout << map[i][k+i-1] << endl;
	}
	
}
//end
//ism
