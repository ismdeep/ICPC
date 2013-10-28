#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j-1)
				{
					cout << " ";
				}
				cout << i*j;
			}
			cout << endl;
		}
	}
	return 0;
}

