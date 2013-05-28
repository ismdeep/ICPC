#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int longint;

longint iGcd(longint a, longint b)
{
    longint tmp;
    while (b)
    {
        tmp = a % b;
        a   = b;
        b   = tmp;
    }
    return a;
}

longint iGcdNum, iLcmNum;

int main()
{
    while (cin >> iGcdNum >> iLcmNum)
    {
        longint iCoPrimeMulSum;
        iCoPrimeMulSum = iLcmNum / iGcdNum;
        longint mid = sqrt(iCoPrimeMulSum + 0.5);
        bool iFound = false;
        while (!iFound)
        {
            if (iCoPrimeMulSum % mid == 0)
            {
                if (iGcd(iCoPrimeMulSum/mid, mid) == 1)
                {
                    cout << mid * iGcdNum << " " << iCoPrimeMulSum / mid * iGcdNum << endl;
                    iFound = true;
                }
            }
            mid--;
        }
    }
}
