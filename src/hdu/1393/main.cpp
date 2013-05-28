#include <iostream>
using namespace std;

int main()
{
    int s, d;
    while (cin >> s >> d && s + d)
    {
        int count = 0;
        int temp = s;
        bool found = false;
        for (int i = 0; !found && count <= 60; i++)
        {
            for (int j = 0; j < d; j++)
            {
                s += temp;
            }
            count++;
            s = s % 60;
            if (s == 0)
            {
                found = true;
            }
        }

        if (found)
        {
            cout << count << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }

    }

    return 0;
}

// end 
// ism 
