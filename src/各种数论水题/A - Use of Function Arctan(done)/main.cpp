#include <iostream>
using namespace std;
long long int t, a, i;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a;
        i = 2 * a;
        while ((i*i+1) % (i-a)){i--;}
        cout << (i*i+1) / (i-a) << endl;
    }
    return 0;
}
