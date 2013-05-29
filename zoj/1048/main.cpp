#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double sum = 0.0;
	for (int i = 0; i < 12; i++)
	{
	    double tmp;
		cin >> tmp;
		sum += tmp;
	}
	
	cout << "$";
	printf("%.2f\n", sum/12);
	
	return 0;
}

// end 
// ism 
