#include "iostream"
using namespace std;

bool right (int value)
{
	int digital = 0;
	while (value)
	{
		digital += (value % 10);
		value /= 10;
	}
	return (0 == digital % 10);
}

int main ()
{
	int a, b;
	while (cin >> a >> b)
	{

		int count = 0;
		for (int j = a; j <= b; j++)

		{
			if (right(j))
			{
				count ++;
			}
		}
	cout << count << endl << endl;
	}
	return 0;
}
