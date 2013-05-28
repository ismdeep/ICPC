#include <iostream>
using namespace std;

int main ()
{
	int n;
	while (cin >> n)
	{
		int nSum = 0;
		while (n--)
		{
			int nTmp;
			cin >> nTmp;
			nSum += nTmp;
		}
		cout << nSum << endl;
	}
	return 0;
}




