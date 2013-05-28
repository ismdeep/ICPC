//project name:2027  统计元音
//Author:键盘杀手
//Creat Date & Time:Fri Apr 13 22:26:54 2012

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.get();
    
    while(t--)
    {
        int a = 0,
            e = 0,
            i = 0,
            o = 0,
            u = 0;
        
        char ch;
        while(cin.get(ch) && ch != '\n')
        {
            if(ch == 'a' || ch == 'A')
            {
                a++;
            }
            
            if(ch == 'e' || ch == 'E')
            {
                e++;
            }
            
            if(ch == 'i' || ch == 'I')
            {
                i++;
            }
            
            if(ch == 'o' || ch == 'O')
            {
                o++;
            }
            
            if(ch == 'u' || ch == 'U')
            {
                u++;
            }
            
        }
        
        
        cout<<"a:"<<a<<endl;
        cout<<"e:"<<e<<endl;
        cout<<"i:"<<i<<endl;
        cout<<"o:"<<o<<endl;
        cout<<"u:"<<u<<endl;
        
        if(t)
        {
            cout<<endl;
        }

        
    }
    
    return 0;
}
//end
//ism
