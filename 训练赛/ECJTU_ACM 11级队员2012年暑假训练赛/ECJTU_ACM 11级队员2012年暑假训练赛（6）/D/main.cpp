#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r1,c1,r2,c2;
    int iCaseCount = 0;

    int iT = 0;
    cin >> iT;
    while (iT--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        iCaseCount++;
        if ((int)fabs(r1-r2) == (int)fabs(c1-c2))
        {
            cout << "Case " << iCaseCount << ": 1" << endl;
        }
        else if ((int)fabs((double)(r1-r2))%2 == (int)fabs((double)(c1-c2))%2)
        {
            cout << "Case " << iCaseCount << ": 2" << endl;
        }
        else
        {
            cout << "Case " << iCaseCount << ": impossible" << endl;
        }
    }
}

