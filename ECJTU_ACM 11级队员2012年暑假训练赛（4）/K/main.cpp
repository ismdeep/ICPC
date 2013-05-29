#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && a + b)
    {
        int ans;
        ans = 1;

        for (int i = 0; i < b; i++)
        {
            ans *= a;

            ans = ans % 10000;
        }

        cout << ans % 1000 << endl;
    }

    return 0;
}

// end
// ism
