#include <iostream>
using namespace std;

int iGcd (int a, int b)
{
	int tmp;
	while (b)
	{
		tmp = a % b;
		a   = b;
		b   = tmp;
	}
	return a;
}

int main ()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << iGcd (a, b) << " " << a * b / iGcd (a, b) << endl;
	}
	return 0;
}


