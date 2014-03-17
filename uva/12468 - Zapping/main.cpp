#include <iostream>
using namespace std;

int main ()
{
	int a, b;
	while (cin >> a >> b, a+b+2)
	{
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		// ---- 
		int min = b - a;
		if (a + 100 - b < min)
		{
			min = a + 100 - b;
		}
		cout << min << endl;
	}
	return 0;
}


