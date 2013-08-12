#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;


#define MAXN 70

string child[MAXN];

int n;
int w,s;

void iInit()
{
    for (int i = 0; i < n; i++)
    {
        cin >> child[i];
    }

    scanf("%d,%d", &w, &s);
}

void iShowChild()
{
    for (int i = 0; i < n; i++)
    {
        cout << child[i] << endl;
    }
    cout << endl;
}

void iStartCount()
{
    int current = w-2;
    int count = n;
    while (count--)
    {
        int tmp = s;
        while (tmp--)
        {
            current++;
            if (current >= n)
            {
                current %= n;
            }
            if (child[current] == "ism")
            {
                while (child[current] == "ism")
                {
                    current++;
                    if (current >= n)
                    {
                        current %= n;
                    }
                }
            }
        }
        cout << child[current] << endl;
        child[current] = "ism";
    }
}

int main()
{
    while (cin >> n)
    {
        iInit();
        //iShowChild();
        iStartCount();
    }
}
