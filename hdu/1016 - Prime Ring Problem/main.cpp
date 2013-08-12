#include <iostream>
#include <fstream>

namespace ismdebug
{
    using namespace std;
    ifstream cin("in.dat", ios::in);
};

//using ismdebug::cin;
using std::cin;
using std::cout;
using std::endl;

#define MAXN 100

int iMap[MAXN];
bool iUsed[MAXN];
bool iPrime[MAXN*MAXN];

int n;

void iInit()
{
    iMap[0] = 1;
    for (int i = 0; i < MAXN; i++)
    {
        iUsed[i] = false;
    }
    iUsed[1] = true;
}

void iMakePrimeMap()
{
    for (int i = 0; i < MAXN * MAXN; i++)
    {
        iPrime[i] = true;
    }

    int iCurrent = 2;
    for (iCurrent = 2; iCurrent <= MAXN; iCurrent++)
    {
        if (iPrime[iCurrent] == true)
        {
            for (int j = iCurrent * iCurrent; j < MAXN; j += iCurrent)
            {
                iPrime[j] = false;
            }
        }
    }

    iPrime[0] = false;
    iPrime[1] = false;
}

void iShowMap()
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << iMap[i] << " ";
    }
    if (n >= 1)

        cout << iMap[n-1] << endl;
}

void iTry(int k)
{
    if (k == n)
    {
        if (iPrime[iMap[0]+iMap[n-1]])
        {
            iShowMap();
        }
    }
    else
    {
        int iNum;
        for (iNum = 1; iNum <= n; iNum++)
        {
            if (!iUsed[iNum] && iPrime[iMap[k-1]+iNum])
            {
                iMap[k] = iNum;
                iUsed[iNum] = true;
                iTry(k+1);
                iUsed[iNum] = false;
            }
        }
    }
}

int main()
{
    iMakePrimeMap();
    int iCaseCount = 0;
    while (cin >> n)
    {
        /*print head*/
        iCaseCount++;
        cout << "Case " << iCaseCount << ":" << endl;

        iInit();

        iTry(1);
        cout << endl;

    }
    return 0;
}

// end
// iCoding@CodeLab
