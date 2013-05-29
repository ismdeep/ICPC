#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int *map = new int[n+1]; /* from 1 - n */
        /* init map[] */
        for (int i = 0; i <=n; i++)
        {
            map[i] = i;
        }
        int count = n;
        int m;
        cin >> m;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            while (x != map[x])
            {
                x = map[x];
            }
            
            if (map[y] != x)
            {
                map[y] = x;
                count--;
            }
        }
        
        /* output count for result */
        cout << count << endl;
    }
    
    return 0;
}

// end 
// ism 
