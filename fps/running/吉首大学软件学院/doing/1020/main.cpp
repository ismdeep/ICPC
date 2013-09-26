#include <iostream>
#include <algorithm>
using namespace std;


int main ()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	sort (a,a+10);
	cout << a[9];
	for (int i = 8; i >= 0; i--)
	{
		cout << " " << a[i];
	}
	return 0;
}



