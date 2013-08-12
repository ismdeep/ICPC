//project name:2035 ( 人见人爱A^B )
//Author:键盘杀手
//Creat Date & Time:Sun Apr 22 22:10:11 2012

#include <iostream>
using namespace std;

int main()
{
    int a, b;
	
	while( cin >> a >> b && a + b)
	{
	    int sum = 1;
		while( b-- )
		{
		    sum = sum * a;
			sum = sum % 100000;
		}
		
		sum = sum % 1000;
		
		cout << sum <<endl;
		
	}
	
    return 0;
}
//end
//ism
