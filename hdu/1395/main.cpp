#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n % 2 == 0 || n == 1)
        {
            cout << "2^? mod " << n << " = 1" << endl;
        }
        else
        {
            int ans = 1;
            int s = 2;
            while (s != 1)
            {
                ans++;
                s = s * 2 % n;
            }
            cout << "2^" << ans << " mod " << n << " = 1" << endl;
        }
    }
    return 0;
}

// end 
// ism 
