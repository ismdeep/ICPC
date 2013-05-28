#include <iostream>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		int nSum = 0;
		int nCount;
		cin >> nCount;
		while (nCount--)
		{
			int nTmp;
			cin >> nTmp;
			nSum += nTmp;
		}
		cout << nSum << endl;
	}
	return 0;
}


