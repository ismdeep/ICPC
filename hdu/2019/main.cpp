//project name:2019
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m&&n+m){
        int time=0;//if(time){cout<<" ";}time++;
        int pre,current;
        cin>>current;
        if(m<current)
        {
            if(time){cout<<" ";}time++;
            cout<<m;
        }
        
        pre=current;
        
        for(int i=1;i<n;i++)
        {
            cin>>current;
            if(m>=pre&&m<current)
            {
                if(time){cout<<" ";}time++;
                cout<<pre<<" "<<m;
            }
            else
            {
                if(time){cout<<" ";}time++;
                cout<<pre;
            }
            pre=current;
        }
        
        if(m>=current)
        {
            if(time){cout<<" ";}time++;
            cout<<current<<" "<<m;
        }
        else
        {
            if(time){cout<<" ";}time++;
            cout<<current;
        }
        
        cout<<endl;
        
    }
    return 0;
}
//end
//ism
