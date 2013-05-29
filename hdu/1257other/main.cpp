#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a[100]={30000};
        int i=1;
        int m,j;
        while(n--)
        {
            cin>>m;
            for(j=0;j<=i;j++)
            {
                if(m<=a[j])
                {
                    a[j]=m;
                    break;
                }
            }
            if(j>i)
            {
                a[++i]=m;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
