#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>

namespace ism
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
};

using ism::cin;
using std::cout;
using std::endl;
#define MAXN 10010

int iNumArr[MAXN / 2];
int iSumArr[MAXN];
int iN, iM;

/*************************************************************/
void iInit()
{
    for (int i = 0; i < iN; i++)
    {
        cin >> iNumArr[i];
    }

    memset(iSumArr, 0, sizeof(iSumArr));

    for (int i = 0; i < iN; i++)
    {
        for (int j = 0; j < i; j++)
        {
            iSumArr[iNumArr[i]+iNumArr[j]]++;
        }
    }
}

void iOutpuResult()
{
    int iCurrent = MAXN - 1;

    while (iM)
    {
        if (iSumArr[iCurrent] > 0)
        {
            cout << iCurrent;
            if (iM != 1)
            {
                cout << " ";
            }
            iSumArr[iCurrent]--;
            iM--;
        }
        else
        {
            while (iSumArr[iCurrent] == 0)
            {
                iCurrent--;
            }
        }
    }
    cout << endl;
}

/*************************************************************/
int main()
{
    while (cin >> iN >> iM)
    {
        iInit();
        iOutpuResult();
    }
    return 0;
}

// end
// ism
