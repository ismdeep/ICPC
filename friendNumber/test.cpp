#include <iostream>
#include <stdio.h>
using namespace std;
/*
class FriendNumber
{
public:
    int x, y;
};

FriendNumber num[100];
*/
int main()
{
    int a,b;
    int count = 0;
    while( cin >> a >> b )
    {
        if( a != b )
        {
            printf("num[%d].x=%d;num[%d].y=%d;\n",count,a,count,b);
            count++;
        }
    }
    
    return 0;
}

