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
		int sum = 0;
		while (n--)
		{
			int m, n, e;
			cin >> m >> n >> e;
			sum += m * e;
		}
		cout << sum << endl;
	}
	return 0;
}