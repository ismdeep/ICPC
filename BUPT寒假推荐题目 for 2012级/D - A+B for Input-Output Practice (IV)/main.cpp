#include <iostream>
using namespace std;

int main ()
{
	int nT;
	while (cin >> nT, nT)
	{
		int n_sum = 0;
		int n_tmp;
		while (nT--)
		{
			cin >> n_tmp;
			n_sum += n_tmp;
		}
		cout << n_sum << endl;
	}
	return 0;
}


