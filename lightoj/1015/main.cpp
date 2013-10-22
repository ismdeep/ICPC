#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int iCaseCount = 1; iCaseCount <= t; iCaseCount++)
	{
		cout << "Case " << iCaseCount << ": ";
		void iInit();
		iInit();
	}
	return 0;
}

void iInit()
{
	int iNumCount;
	cin >> iNumCount;
	int sum = 0;
	for (int i = 0; i < iNumCount; i++)
	{
		int iNum;
		cin >> iNum;
		if (iNum >= 0)
		{
			sum += iNum;
		}
		//sum += iNum;
	}
	cout << sum << endl;
}

// end 
// iCoding@CodeLab

