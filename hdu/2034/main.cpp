#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 110

int iAarray[MAXN];

int n, m;

bool cmp(int a, int b)
{
    return a < b? true: false;
}

int main()
{
    while (cin >> n >> m && n + m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> iAarray[i];
        }

        // start input data and delete if the input data is in the set of iAarray
        for (int i = 0; i < m; i++)
        {
            int iTmp;
            cin >> iTmp;
            for (int j =0; j < n; j++)
            {
                if (iAarray[j] == iTmp)
                {
                    iAarray[j] = iAarray[n-1];
                    n--;
                }
            }
        }
        if (n > 0)
        {
            sort(iAarray,iAarray+n,cmp);
            for (int i = 0; i < n; i++)
            {
                cout << iAarray[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
    return 0;
}











