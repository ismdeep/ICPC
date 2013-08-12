#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && ! (n == 0 && m == 0))
    {
        int x, y;
        bool found = false;
        for (x = (0 - fabs(m)); !found && x <= fabs(m); x++)
        {
            if (x != 0 && m % x == 0)
            {
                y = m / x;
                if (x + y == n)
                {
                    found = true;
                }
            }
        }

        if (found)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No"  << endl;
        }
    }
    return 0;
}

// end
// ism
