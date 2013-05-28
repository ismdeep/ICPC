//project name:2071 ( Max Num )
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Sun Apr 22 05:56:01 2012

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
	cin >> t;
	
	while( t-- )
	{
	    int n;
		cin >> n;
		float max, temp;
		cin >> max;
		n--;
		while ( n-- )
		{
		    cin >> temp;
			if( temp > max )
			{
			    max = temp;
			}
		}
		
		printf("%.2f\n",max);
		
	}
	
    return 0;
}
//end
//ism
