#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n;


class Node
{
    public:
    string ID;
    string value;
};

bool cmp(Node s1, Node s2)
{
    return strcmp(s1.ID.c_str(), s2.ID.c_str()) ? false: true;
}

Node variable[1000];

int main()
{
    int iProgramCount = 1;
    while (cin >> n && n)
    {
        int top = 0;
        variable[0].ID = "a";
        variable[0].value = "a";

        for (int count = 0; count < n; count++)
        {
            string s1, s2;
            cin >> s1;
            cin >> s2;
            cin >> s2;

            int id1, id2;
            bool found = false;
            for (int i = 0; !found && i <= top; i++)
            {
                if (s1 == variable[i].ID)
                {
                    id1 = i;
                    found = true;
                }
            }
            if (!found)
            {
                top++;
                variable[top].ID = s1;
                variable[top].value = "unknow";
                id1 = top;
            }

            found = false;
            for (int i = 0; !found && i <= top; i++)
            {
                if (s2 == variable[i].ID)
                {
                    id2 = i;
                    found = true;
                }
            }
            if (!found)
            {
                top++;
                variable[top].ID = s2;
                variable[top].value = "unknow";
                id2 = top;
            }

            variable[id1].value = variable[id2].value;
        }

        sort(variable, variable+top, cmp);
        // show
        if (iProgramCount != 1)
        {
            cout << endl;
        }
        cout << "Program #" << iProgramCount << endl;
        int spacecount = 0;
        for (int i = 0; i <= top; i++)
        {
            if (variable[i].value == "a")
            {
                if (spacecount != 0)
                {
                    cout << " ";
                }
                spacecount++;
                cout << variable[i].ID;
            }
        }
        if (spacecount == 0)
        {
            cout << "none";
        }
        cout << endl;
    }

    return 0;
}

// end
// ism

