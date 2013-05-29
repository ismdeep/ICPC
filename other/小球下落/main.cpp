#include <iostream>
using namespace std;

const bool open = true;
const bool closed = false;

int calNode(int depth)
{
    int result = 1;
    result = result << depth;
    
    result--;
    //cout << result << endl;
    
    return result;
    
}

int main()
{
    int depth,ball;
    while( cin >> depth >> ball )
    {
        int nodeTop = calNode(depth)+1;
        bool *tree = new bool[nodeTop+1];
        
        for(int i = 0; i <= nodeTop; i++)
        {
            tree[i] = closed;
        }
        
        int current;
        for(int i = 1; i <= ball; i++)
        {
            current = 1;
            for(int i = 1; i < depth; i++)
            {
                if(tree[current] == open)
                {
                    tree[current] = closed;
                    current = current * 2 + 1;
                }
                else
                {
                    tree[current] = open;
                    current = current * 2;
                }
            }
        }
        
        cout << current << endl;
    }
    
    return 0;
}
// end
// ism

