#include <iostream>
#include <cstring>
using namespace std;

string s_yes = "YES";
string s_no  = "NO";

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        if (s.length() != t.length())
        {
            cout << s_no << endl;
        }
        else
        {
            bool yes = true;
            for (int i = 0; yes && i < (int)s.length(); i++)
            {
                if (s[i] != t[s.length()-i-1])
                {
                    yes = false;
                }
            }
            if (yes)
            {
                cout << s_yes << endl;
            }
            else
            {
                cout << s_no  << endl;
            }
        }
    }
    return 0;
}


// end
// iCoding@CodeLab
