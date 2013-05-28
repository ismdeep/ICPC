#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 20000

int data[MAXN];
int n;

int main ()
{
    while (cin >> n)
    {
        // input data
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        // sort
        sort (data, data + n);
        // output result
        cout << data[n/2] << endl;
    }
    return 0;
}

// end
// iCoding
// CodeLab

