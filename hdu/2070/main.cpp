//project name:2070 ( Fibbonacci Number )
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Sun Apr 22 05:45:44 2012

#include <iostream>
using namespace std;

class FibbonacciNumber
{
private:
    long long int a[51];

public:
	FibbonacciNumber();
	long long int getVar(int k)
	{
	    return a[k-1];
	}
};

FibbonacciNumber::FibbonacciNumber()
{
    a[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= 50; i++)
	{
	    a[i] = a[i-1] + a[i-2];
	}
}

int main()
{
    
	FibbonacciNumber fn;
	
	int n;
	while( cin >> n && n != -1)
	{
	    cout << fn.getVar(n) << endl;
	}
	
    return 0;
}
//end
//ism
