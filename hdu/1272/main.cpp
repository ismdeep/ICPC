#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100000

const bool used    = true;
const bool un_used = false;

class Link
{
public:
    int start;
    int end;
};

int main()
{
    int a, b;
    
    while( scanf("%d%d",&a,&b) != EOF && ( a > 0 && b > 0 ) )
    {
        Link *link;
        link = new Link[MAX * 2];
        int top = -1;
        top++;
        link[top].start = a;
        link[top].end   = b;
        while( scanf("%d%d",&a,&b) != EOF && a+b )
        {
            top++;
            link[top].start = a;
            link[top].end   = b;
        }
        
        bool statue[MAX + 1];
        for(int i = 0; i <= MAX; i++)
        {
            statue[i] = un_used;
        }
        
        bool yes = true;
        for(int i = 0; yes && i <= top; i++)
        {
            if( statue[link[i].start] == used && statue[link[i].end] == used )
            {
                yes = false;
                cout << "--break!!" << endl;
                cout << "--" << link[i].start << "  " << link[i].end << endl;
            }
            else
            {
                statue[link[i].start] = used;
                statue[link[i].end]   = used;
            }
            
        }
        
        //output for result
        if(yes)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        
        
        // at the end of this loop process
        delete[] link;
    }
    
    return 0;
}
