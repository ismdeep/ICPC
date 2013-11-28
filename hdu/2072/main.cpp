#include <iostream>
#include <set>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line),line != "#")
    {
        istringstream iss(line);
        set<string> s((istream_iterator<string>(iss)),istream_iterator<string>());
        cout << s.size() << endl;
    }
    return 0;
}
