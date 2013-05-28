#include <iostream>
using namespace std;

int main ()
{
	int t;
	bool flag = false;
	cin >> t;
	while (t--)
	{
		if (flag)
		{
			cout << endl;
		}
		flag = true;
		//----
		int n;
		int nSum = 0;
		int nTmp;
		cin >> n;
		while (n--)
		{
			cin >> nTmp;
			nSum += nTmp;
		}
		cout << nSum << endl;
	}
	return 0;
}


