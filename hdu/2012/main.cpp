//project name:2012
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b && a+b)
    {
        int flag = true;
        
        //容错处理，如果 a > b,交换a b 的值
        if(a > b)
        {
            int intTemp = a;
            a = b;
            b = intTemp;
        }
        
        //开始判断是否存在 40 41 44 49 在其中
        if(a <= 40 && b>=40)
        {
            flag=false;
        }
        if(a <= 41 && b>=41)
        {
            flag=false;
        }
        if(a <= 44 && b>=44)
        {
            flag=false;
        }
        if(a <= 49 && b>=49)
        {
            flag=false;
        }
        
        //最后判断flag的值
        if(flag)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"Sorry"<<endl;
        }
        
    }
    
    return 0;
}
//end
//ism
/*40 41 44 49*/
