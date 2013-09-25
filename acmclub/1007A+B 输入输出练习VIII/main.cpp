#include <iostream>
using namespace std;



int main ()
{
	int n;
	cin >> n;
	for (int index = 1; index <- n; index++)
	{
		if (index-1)
		{
			cout << endl;
		}
		int t;
		cin >> t;
		int sum = 0;
		while (t--)
		{
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
		cout << sum << endl;
	}
	return 0;
}



