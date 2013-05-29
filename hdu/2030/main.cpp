//project name:2030 汉字统计
//Author:键盘杀手
//Creat Date & Time:Sat Apr 14 16:35:55 2012

#include <iostream>
using namespace std;

int main()
{
    int t;
    
    cin>>t;
    
    cin.get();
    
    while(t--)
    {
        char ch;
        int count = 0;
        
        while(cin.get(ch) && ch != '\n')
        {
            if(ch < 0)
            {
                count++;
                cin.get(ch);
            }
        }
        
        cout<< count << endl;
    }
    return 0;
}
//end
//ism
/*
如果你真心l ve一个人,就把信息发给在线的20个人,包括我如果10个人,回你你的愿望在4月14晚上实现,不许不发,因为你要幸福,也给我回一个吧,嘻嘻…    
*/
