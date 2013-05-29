#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int time = 1; time <= t; time++)
    {
        cout << endl;
        int a, b;
        int ans = 0;
        cin >> a >> b;
        ans = 4 * fabs(a-b) + 3 + 5 + 3 + 4 * fabs(a) + 3 + 5;

        cout << "Case "<< time <<": ";
        cout << ans << endl;
    }
    return 0;
}

// end
// ism
