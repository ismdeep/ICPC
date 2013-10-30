#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime (int value)
{
    if (value <= 1)
    {
        return false;
    }
    else
    {
        bool isok = true;
        for (int i = 2; i < value; i++)
        {
            if (value%i==0)
            {
                isok = false;
            }
        }
        return isok;
    }
}

long long int a[1000000];
int n,k;


int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort (a,a+n);
    long long int m = a[n-k]-a[k-1];
    if (is_prime(m))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    cout << m << endl;
    return 0;
}
