#include <stdarg.h>
#include <iostream>
using namespace std;

int max(int num, ...)
{
    int m = -0x7FFFFFF;
    va_list ap;
    va_start(ap, num);
    for (int i = 0; i < num; i++)
    {
        int t = va_arg(ap, int);
        if (t > m)
        {
            m = t;
        }
    }

    va_end(ap);

    return m;
}

int main()
{
    cout << max(1,23234,3,4,42,23,4,234234,34) << endl;
    return 0;
}

// end
// ism
