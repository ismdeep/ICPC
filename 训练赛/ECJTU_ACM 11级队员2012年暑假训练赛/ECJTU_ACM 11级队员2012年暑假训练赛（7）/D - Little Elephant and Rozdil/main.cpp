#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long int longint;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        longint min;
        longint minmin;
        int flag;
        cin >> minmin;
        for (int i = 1; i < n; i++)
        {
            longint tmp;
            cin >> tmp;
            flag = 0;
            if (tmp <= minmin)
            {
                min = minmin;
                minmin = tmp;
                flag = i;
            }
        }

        if (n == 1)
        {
            cout << "1" << endl;
        }
        else if (min == minmin)
        {
            cout << "Still Rozdil" << endl;
        }
        else
        {
            cout << flag + 1 << endl;
        }
    }
    return 0;
}

// end
// ism
