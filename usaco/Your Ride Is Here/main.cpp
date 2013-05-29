/*
ID: honi.li1
PROG:ride 
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <fstream>
namespace ismdebug
{
	using namespace std;
	ifstream cin("ride.in", ios::in);
	ofstream cout("ride.out", ios::out);
}


using ismdebug::cin;
using ismdebug::cout;
using std::string;
using std::endl;

#define MOD 47

string comet, group;

void iJudge()
{
	int iSumComet = 1;
	int iSumGroup = 1;
	//
	for (int i = 0; i <= comet.length(); i++)
	{
		iSumComet *= (comet[i] - 'A' + 1);
		iSumComet %= MOD;
	}

	for (int i = 0; i <= group.length(); i++)
	{
		iSumGroup *= (group[i] - 'A' + 1);
		iSumGroup %= MOD;
	}

	if (iSumComet == iSumGroup)
	{
		cout << "GO" << endl;
	}
	else
	{
		cout << "STAY" << endl;
	}
}

int main()
{
	while (cin >> comet >> group)
	{
		iJudge();
	}
	return 0;
}
