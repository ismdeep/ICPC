#include <iostream>
using namespace std;

typedef unsigned long long int longint;

longint* iMap;

int main()
{
    int n;
    while (cin >> n)
    {
        iMap = new longint[n];
        for (int i = 0; i < n; i++)
        {
            cin >> iMap[i];
        }

        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (iMap[i] < iMap[flag])
            {
                flag = i;
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (iMap[i] == iMap[flag])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << flag + 1 << endl;
        }
        else
        {
            cout << "Still Rozdil" << endl;
        }

        delete[] iMap;
    }
    return 0;
}


// end
// ism


