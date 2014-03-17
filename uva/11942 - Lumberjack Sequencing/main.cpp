#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	cout << "Lumberjacks:" << endl;
	while (t--)
	{
		bool left_big = false;
		bool right_big = false;
		int a, b;
		cin >> a;
		b = a;
		for (int i = 1; i < 10; i++)
		{
			a = b;
			cin >> b;
			if (a > b)
			{
				left_big = true;
			}
			if (a < b)
			{
				right_big = true;
			}
		}
		if (left_big ^ right_big)
		{
			cout << "Ordered" << endl;
		}
		else
		{
			cout << "Unordered" << endl;
		}
	}
	return 0;
}

