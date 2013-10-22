#include <iostream>
using namespace std;

#define MAXN 20000

char map[MAXN][MAXN];

void iDraw(char iCh, int iNum)
{
    int iWidth = iNum / 6 + 1;

    for (int i = 0; i < iNum; i++)
    {
        for (int j = 0; j < iNum - 1; j++)
        {
            map[i][j] = 32;
        }
    }

    // filling the blank
    int mid;
    mid = iNum / 2;
    if (iNum % 2 == 0)
    {
        mid--;
    }


    for (int j = iWidth; j <= iNum - 2 - iWidth; j++)
    {
        map[0][j]      = iCh;
        map[mid][j]    = iCh;
        map[iNum-1][j] = iCh;
    }
    for(int i = 1;        i < mid;  i++)
    {
        for (int j = 0; j < iWidth; j++)
        {
            map[i][j]        = iCh;
            map[i][iNum-2-j] = iCh;
        }
    }
    for (int i = mid + 1; i < iNum - 1; i++)
    {
        for (int j = 0; j < iWidth; j++)
        {
            map[i][j]        = iCh;
            map[i][iNum-2-j] = iCh;
        }
    }

    // output result
    for (int i = 0; i < iNum; i++)
    {
        for (int j = 0; j < iNum - 1; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int time = 0; time < t; time++)
    {
        if (time)
        {
            cout << endl;
        }

        char ch;
        int num;

        cin >> ch >> num;

        if (num == 4)
        {
            cout << " " << ch   << " " << endl;
            cout << ch  << " " << ch  << endl;
            cout << " " << ch   << " " << endl;
        }
        else if (num == 5)
        {
            cout << " " << ch  << " " << endl;
            cout << ch  << " " << ch  << endl;
            cout << " " << ch  << " " << endl;
            cout << ch  << " " << ch  << endl;
            cout << " " << ch  << " " << endl;
        }
        else if (num == 6)
        {
            cout << "  " << ch << ch << "  " << endl;
            cout << ch << ch << "  " << ch << ch << endl;
            cout << "  " << ch << ch << "  " << endl;
            cout << ch << ch << "  " << ch << ch << endl;
            cout << ch << ch << "  " << ch << ch << endl;
            cout << "  " << ch << ch << "  " << endl;
        }
        else
        {
            iDraw(ch, num);
        }
    }

    return 0;
}

// end
// ism
