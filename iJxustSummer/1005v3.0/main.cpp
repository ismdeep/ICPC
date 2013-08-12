#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
namespace ismdebug
{
    using namespace std;
    ifstream cin("in.dat",ios::in);
};

//using ismdebug::cin;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

#define iMAXN 50000
int n, m;
string iStr[iMAXN];
map<string,int> iMap;
int iAns;

void iInit()
{
    for (int i = 0; i < n; i++)
    {
        string str_tmp;
        cin >> str_tmp;
        iStr[i] = str_tmp;
    }
    iAns = 0;
}

void iCalAnswer()
{
    iMap.clear();
    for (int i = 0 ; i < m; i++)
    {
        string str_tmp;
        cin >> str_tmp;
        iMap[str_tmp] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        string str_tmp;
        str_tmp = iStr[i];
        if (iMap[str_tmp] == 0)
        {
            iMap[str_tmp]++;
            iAns++;
        }
    }

    cout << iAns << endl;
}

int main()
{
    while (cin >> n >> m)
    {
        iInit();
        iCalAnswer();
    }
}
