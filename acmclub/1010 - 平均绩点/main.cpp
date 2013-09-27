#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;


int main()
{
    string line;
    while (getline(cin,line))
    {
        stringstream str_in;
        str_in << line << endl;
        bool legal = true;
        char ch;
        int count = 0;
        int sum = 0;
        while (str_in >> ch)
        {
            if (ch >= 'A' && ch <= 'D')
            {
                sum += (4 - (ch - 'A'));
                count++;
            }
            else if ('F' == ch)
            {
                sum += 0;
                count++;
            }
            else
            {
                legal = false;
            }
        }
        if (legal)
        {
            printf ("%.2lf\n", (double)sum / (double)count);
        }
        else
        {
            cout << "Unknown" << endl;
        }
    }
    return 0;
}
