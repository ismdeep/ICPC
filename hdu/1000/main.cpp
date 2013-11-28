#include <iostream>
#include <fstream>

namespace ismdebug
{
    using namespace std;
    ifstream cin ("in.dat", ios::in);
    ofstream cout ("out.dat", ios::out);
};

using ismdebug::cin;
using ismdebug::cout;
//using std::cin;
//using std::cout;
using std::endl;


int main()
{
    int iNumber1, iNumber2;
    while (cin >> iNumber1 >> iNumber2)
    {
        cout << iNumber1 + iNumber2 << endl;
    }
    return 0;
}

// end
// ism
