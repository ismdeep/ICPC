#include <iostream>
#include <string>

using namespace std;

#define MAXN 1000

char iMap[MAXN][MAXN];
char iIterationMap[MAXN][MAXN];
int n, timecount;

void iInit()
{
    cin >> n >> timecount;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            iMap[i][j] = s[j];
        }
    }
}

void iShowMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << iMap[i][j] << " ";
        }
        cout << endl;
    }
}

void iIterate()
{
    while (timecount--)
    {
        for (int i = 1; i < n-1; i++)
        {
            for (int j = 1; j < n-1; j++)
            {
                int black = 0;
                int white = 0;
                if (iMap[i-1][j-1] == 'w'){white++;}else {black++;}if (iMap[i-1][j] == 'w'){white++;}else {black++;}if (iMap[i-1][j+1] == 'w'){white++;}else {black++;}
                if (iMap[i][j-1]   == 'w'){white++;}else {black++;}if (iMap[i][j]   == 'w'){white++;}else {black++;}if (iMap[i][j+1]   == 'w'){white++;}else {black++;}
                if (iMap[i+1][j-1] == 'w'){white++;}else {black++;}if (iMap[i+1][j] == 'w'){white++;}else {black++;}if (iMap[i+1][j+1] == 'w'){white++;}else {black++;}
                if (black > white)
                {
                    iIterationMap[i][j] = 'b';
                }
                else
                {
                    iIterationMap[i][j] = 'w';
                }
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                iMap[i][j] = iIterationMap[i][j];
            }
        }
    }
}

void iCountResult()
{
    int black = 0;
    int white = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (iMap[i][j] == 'w')
            {
                white++;
            }
            else
            {
                black++;
            }
        }
    }
    //cout << white << " " << black << endl;
    cout << black << " " << white << endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        iInit();
        iIterate();
        //iShowMap();
        iCountResult();
    }
    return 0;
}

// end
// ism
