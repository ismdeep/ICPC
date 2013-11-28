#include <iostream>
using namespace std;

char iMap[12] = {'A', 'a', 'Y', 'y', 'E', 'e', 'U', 'u', 'O', 'o', 'I', 'i'};

bool iInMap(char c)
{
    bool yes = false;
    int flag = 11;
    while (!yes && flag >= 0)
    {
        if (iMap[flag] == c)
        {
            yes = true;
        }
        flag--;
    }
    return yes;
}

int main()
{
    string s;
    while (cin >> s)
    {
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (!iInMap(s[i]))
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] += 32;
                }
                cout << "." << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}

// end
// ism

