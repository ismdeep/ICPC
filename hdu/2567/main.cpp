#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;

        cin >> s1 >> s2;

        for (int i = 0; i < (int)s1.length() / 2; i++)
        {
            cout << s1[i];
        }
        cout << s2;
        for (int i = s1.length() / 2; i < (int)s1.length(); i++)
        {
            cout << s1[i];
        }
        cout << endl;
    }
    return 0;
}

// end
// ism
