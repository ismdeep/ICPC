#include <iostream>
#include <cmath>
using namespace std;

int iBookshelf;
int n;
int iMin;

int iCurrent;

int iMap[25];

void iInit()
{
    iMin = -1;
    iCurrent = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> iMap[i];
    }
}
void iTry(int k)
{
    if (k == n + 1)
    {
        return;
    }
    else
    {
        // not in
        if (((iBookshelf - iCurrent) < iMin && (iBookshelf - iCurrent) >= 0)|| iMin == -1)
        {
            iMin = iBookshelf - iCurrent;
            iTry(k+1);
        }

        // in it
        iCurrent += iMap[k];
        if (((iBookshelf - iCurrent) < iMin && (iBookshelf - iCurrent) >= 0)|| iMin == -1)
        {
            iMin = iBookshelf - iCurrent;
            iTry(k+1);
        }
        iCurrent -= iMap[k];
    }
}

int main()
{
    while (cin >> n >> iBookshelf)
    {
        iInit();
        iTry(1);
        cout << iMin << endl;
    }
    return 0;
}

// end
// ism
