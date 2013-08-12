#include <iostream>
using namespace std;

int result[10000];

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int top=-1;
        while(n!=1){
            if(n%2==1){
                top++;
                result[top]=n;
                n=n*3+1;
            }
            else{
                n=n/2;
            }
        }
        if(top==-1){cout<<"No number can be output !"<<endl;}
        else{
            for(int i=0;i<top;i++){
                cout<<result[i]<<" ";
            }
            cout<<result[top]<<endl;
        }
    }
    
    return 0;
}
//end
//ism
