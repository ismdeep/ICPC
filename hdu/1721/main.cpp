#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f, g, h;
    while (cin >> a && a >= 0)
    {
        cin >> b >> c >> d >> e >> f >> g >> h;

        e += g;
        g =  0;

        a += h;
        h  = 0;

        a += f;
        f  = 0;

        a += c;
        c  = 0;

        if (a == (b + d + e))
        {
            cout << "All the seeds can be cleared away!" << endl;
        }
        else
        {
            cout << "Sorry,it can't be cleared away!"    << endl;
        }
    }
    return 0;
}

// end
// ism
