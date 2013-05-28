#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
	cin >> n;
	for (int index = 1; index <= n; index++)
	{
		int a, b;
		cin >> a >> b;
		cout << "Scenario #" << index << ":" << endl;
		if(a%2!=0&&b%2!=0)
		{
			printf("%0.2f\n\n",(float)a*b-1+sqrt(2.0));
				
		}
		else
		{
			printf("%0.2f\n\n",(float)a*b);
			
		}
		
	}
	
	return 0;
}

// end 
// ism 
