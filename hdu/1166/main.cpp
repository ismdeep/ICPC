#include <iostream>
#include <fstream>
#include <cstring>
namespace ismdebug
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
    void debug()
    {
        cout << "--debug msg!" << endl;
    }
};

//using ismdebug::cin;
//using ismdebug::debug;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAXN 50050

int **iMap;
int n;

//initial
void iInit()
{
    cin >> n;
    iMap = new int*[n+1];
    for (int i = 0; i <= n; i++)
    {
        iMap[i] = new int[n+1];
    }
    memset(iMap, 0, sizeof(iMap));
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        iMap[i][i] = tmp;
    }
    for (int level = 2; level <= n; level++)
    {
        for (int j = level; j <= n; j++)
        {
            iMap[j-level+1][j] = iMap[j-level+1][j-1] + iMap[j-level+2][j] - iMap[j-level+2][j-1];
        }
    }
}

// show map for debuging
void iShowMap()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << iMap[i][j] << " ";
        }
        cout << endl;
    }
}

// i would like to free the memory I used just now
void iFreeMemory()
{
    for (int i = 0; i <= n; i++)
    {
        delete[] iMap[i];
    }
    delete[] iMap;
}

void iAdd(int node, int num)
{
    for (int i = 1; i <= node; i++)
    {
        for (int j = node; j <= n; j++)
        {
            iMap[i][j] += num;
        }
    }
}

void iSub(int node, int num)
{
    for (int i = 1; i <= node; i++)
    {
        for (int j = node; j <= n; j++)
        {
            iMap[i][j] -= num;
        }
    }
}

void iQuery(int start, int end)
{
    cout << iMap[start][end] << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int iCaseID = 1; iCaseID <= t; iCaseID++)
    {
        iInit();
        //iShowMap();
        cout << "Case " << iCaseID << ":" << endl;
        string instru;
        while (cin >> instru && instru != "End")
        {
            if (instru == "Add")
            {
                int node, num;
                cin >> node >> num;
                iAdd(node, num);
            }
            if (instru == "Sub")
            {
                int node, num;
                cin >> node >> num;
                iSub(node, num);
            }
            if (instru == "Query")
            {
                int start, end;
                cin >> start >> end;
                iQuery(start, end);
            }
        }
        iFreeMemory();
    }

    return 0;
}

// end
// ism
