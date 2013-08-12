#include <iostream>
using namespace std;

#ifndef MAXN
#define MAXN 1000
#endif

const string BACK    = "BACK";
const string FORWARD = "FORWARD";
const string VISIT   = "VISIT";
const string QUIT    = "QUIT";

string web_list[MAXN];
int iTop;
int iCurrent;

void iIgnoredMsg()
{
	cout << "Ignored" << endl;
}

int main()
{
	int iT;
	cin >> iT;
	for (int iCaseID = 1; iCaseID <= iT; iCaseID++)
	{
		cout << "Case " << iCaseID << ":" << endl;
		//
		//
		// init for web_list
		iTop     = 0;
		iCurrent = 0;
		web_list[iTop] = "http://www.lightoj.com/";
		//
		//
		string iInstruc;
		while (cin >> iInstruc && iInstruc != QUIT)
		{
			if (iInstruc == BACK)
			{
				if (iCurrent > 0)
				{
					iCurrent--;
					cout << web_list[iCurrent] << endl;
				}
				else
				{
					iIgnoredMsg();
				}
			}
			if (iInstruc == FORWARD)
			{
				if (iCurrent < iTop)
				{
					iCurrent++;
					cout << web_list[iCurrent] << endl;
				}
				else
				{
					iIgnoredMsg();
				}
			}
			if (iInstruc == VISIT)
			{
				iCurrent++;
				iTop = iCurrent;
				string tmp_link;
				cin >> tmp_link;
				web_list[iCurrent] = tmp_link;
				cout << tmp_link << endl;
			}
		}
	}
	return 0;
}

// end 
// iCoding@CodeLab
//
//
