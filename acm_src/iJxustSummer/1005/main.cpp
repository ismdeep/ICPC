#include <iostream>
#include <fstream>
#include <stdio.h>

namespace ismdebug
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
};

using ismdebug::cin;
//using std::cin;
using std::cout;
using std::endl;
using std::string;
/*********************************************************************/
#define MAXN 50500

char s[20];

string iStrStack[MAXN];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int top = -1;
        while (n--)
        {
            //cin >> s;
            scanf("%s", s);
            bool found = false;
            for (int i = 0; !found && i <= top; i++)
            {
                if (iStrStack[i] == s)
                {
                    found = true;
                }
            }
            if (!found)
            {
                top++;
                iStrStack[top] = s;
            }
        }

        int unknow = 0;
        while (m--)
        {
            //cin >> s;
            scanf("%s", s);
            for (int i = 0; i <= top; i++)
            {
                if (iStrStack[i] == s)
                {
                    iStrStack[i] = "01010012";
                }
            }
        }

        for (int i = 0; i <= top; i++)
        {
            if (iStrStack[i] != "01010012")
            {
                unknow++;
            }
        }
        cout << unknow << endl;

    }
}

