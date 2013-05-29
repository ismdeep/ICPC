#include <iostream>
using namespace std;

#define MOD 91
#define MAXN 14000

int main()
{
    for (int i = 1; i <= MAXN; i++)
    {
        for (int j = 1; j <= MAXN; j++)
        {
            if ((((i%MOD) * (j%MOD)) % MOD) != ((i*j) % MOD))
            {
                cout << i << " " << j << endl;
            }
        }
    }
}
