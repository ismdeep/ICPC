#include <iostream>
using namespace std;

#ifndef MAXN
#define MAXN 200
#endif

int a[MAXN];

int main()
{
	int iT;
	cin >> iT;
	for (int iCaseID = 1; iCaseID <= iT; iCaseID++)
	{
		cout << "Case " << iCaseID << ":" << endl;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//
		//
		while (m--)
		{
			char instruc;
			cin >> instruc;
			if (instruc == 'S')
			{
				int num;
				cin >> num;
				for (int i = 0; i < n; i++)
				{
					a[i] += num;
				}
			}
			if (instruc == 'M')
			{
				int num;
				cin >> num;
				for (int i = 0; i < n; i++)
				{
					a[i] *= num;
				}
			}
			if (instruc == 'D')
			{
				int num;
				cin >> num;
				for (int i = 0; i < n; i++)
				{
					a[i] /= num;
				}
			}
			if (instruc == 'R')
			{
				// reverse all
				for (int i = 0; i * 2 < n; i++)
				{
					int tmp;
					tmp      = a[i];
					a[i]     = a[n-i-1];
					a[n-i-1] = tmp;
				}
			}
			if (instruc == 'P')
			{
				int x1, x2;
				cin >> x1 >> x2;
				int tmp;
				tmp   = a[x1];
				a[x1] = a[x2];
				a[x2] = tmp;
			}
		}
		//
		//
		for (int i = 0; i < n - 1; i++)
		{
			cout << a[i] << " ";
		}
		cout << a[n-1] << endl;
	}
	//
	//
	return 0;
}

// end 
// iCoding@CodeLab
//

