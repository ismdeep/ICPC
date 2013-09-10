#include <iostream>
using namespace std;

class ballon{
public:
string color;
int number;
};

int main(){
    int n;
    while(cin>>n&&n){
        int top=-1;
        ballon *a=new ballon[n];
        string colorTemp;
        int t;t=n;
        while(t--){
            cin>>colorTemp;
            
            bool found=false;
            for(int i=0;i<=top&&!found;i++){
                if(colorTemp==a[i].color){
                    a[i].number++;
                    found=true;
                }
            }
        
            if(!found){
                top++;
            }
            a[top].color=colorTemp;
            a[top].number=1;
        }
        
        int max=0;
        for(int i=1;i<=top;i++){
            if(a[max].number<a[i].number){
                max=i;
            }
        }
        cout<<a[max].color<<endl;
    }
    
    return 0;
}
//end
//ism
