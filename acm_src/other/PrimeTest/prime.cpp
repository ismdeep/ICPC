#include <iostream>
#include <cmath>
using namespace std;

#define LENGTH 20000000

bool isprime(int k)
{
    int stop = sqrt(k);
    int yes = true;
    for (int i = 2; yes && i <= stop; i++)
    {
        if (k % i == 0)
        {
            yes = false;
        }
    }
    return yes;
}

int main()
{
    for (int i = 2; i < LENGTH; i++)
    {
        if (isprime(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}

// end 
// ism 

