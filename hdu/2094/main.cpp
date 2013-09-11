#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string str;
    int n, i, j;
    while (cin >> n && n)
    {
        map<string, int> all, loser;
        for (j = i = 0; i < n; i++)
        {
            cin >> str;
            if (!all.count(str)) all.insert(pair<string, int> (str, 2 * i));
            cin >> str;
            if (!all.count(str)) all.insert(pair<string, int> (str, 2 * i + 1));
            if (!loser.count(str)) loser.insert(pair<string, int> (str, j++));
        }
        if (all.size() - loser.size() == 1)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}

// end
// ism
