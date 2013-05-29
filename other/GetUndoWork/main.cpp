#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile1("mine.txt", ios::in);
    ifstream infile2("other.txt", ios::in);
    
    string mine[1000];
    int top = -1;
    
    string s;
    while (infile1 >> s)
    {
        top++;
        
        mine[top] = s;
        
        infile1 >> s;
    }
    
    string other[1000];
    int top_other = -1;
    while (infile2 >> s)
    {
        top_other++;
        other[top_other] = s;
        infile2 >> s;
    }
    
    bool exist[1000];
    for (int i = 0; i < 1000; i++)
    {
        exist[i] = false;
    }
    
    for (int i = 0; i <= top_other; i++)
    {
        for (int j = 0; j <= top; j++)
        {
            if (other[i] == mine[j])
            {
                exist[i] = true;
            }
        }
    }
    
    // output
    for (int i = 0; i <= top_other; i++)
    {
        if (!exist[i])
        {
            cout << other[i];
        }
        cout << endl;
    }
    
    return 0;
}

// end 
// ism 
