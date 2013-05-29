//project name:2024  C语言合法标识符
//Author:键盘杀手
//Creat Date & Time:Fri Apr 13 19:07:01 2012

#include <iostream>
using namespace std;

char a[60];
int top;

int main()
{
    int n;
    cin>>n;
    cin.get();
    while(n--)
    {
        top = -1;
        char ch;
        
        //get a line for var name 
        while(cin.get(ch) && ch != '\n')
        {
            top++;
            a[top] = ch;
        }
        
        // judge if it's legal for var name in c language
        bool flag = true;
        for(int i = 0; flag && i <= top;i++)
        {
            if(
                (a[i] != '_')
                &&!(a[i] >= 'a' && a[i] <= 'z')
                &&!(a[i] >= 'A' && a[i] <= 'Z')
                &&!(a[i] >= '0' && a[i] <= '9')
            ){
                flag = false;
            }
        }
        
        if(a[0] >= '0' && a[0] <= '9')
        {
            flag = false;
        }
        
        if(flag)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
        
        
    }
    return 0;
}
//end
//ism
