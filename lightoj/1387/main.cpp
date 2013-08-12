#include <iostream>
using namespace std;

int sum;

void iStartCal()
{
	sum = 0;
	int m;
	cin >> m;
	while (m--)
	{
		string instruc;
		cin >> instruc;
		if (instruc == "report")
		{
			cout << sum << endl;
		}
		if (instruc == "donate")
		{
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
	}
}

void iShowHeadMsg(int iCaseID)
{
	cout << "Case " << iCaseID << ":" << endl;
}


int main()
{
	int iT;
	cin >> iT;
	for (int iCaseID = 1; iCaseID <= iT; iCaseID++)
	{
		iShowHeadMsg(iCaseID);
		iStartCal();
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

