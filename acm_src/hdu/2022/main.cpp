//project name:2022
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Fri Apr 13 14:06:59 2012

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n , m;
    
    while(cin>>n>>m)
    {
        int x = 0 , y = 0;
        int max=0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j =1; j <= m; j++)
            {
                int temp;
                cin >> temp;
                if(fabs(temp) > fabs(max))
                {
                    max=temp;
                    x = i;
                    y = j;
                }
            }
        }
        
        //output the result 
        cout<<x<<" "<<y<<" "<<max<<endl;
        
    }
    
    return 0;
}
//end
//ism
