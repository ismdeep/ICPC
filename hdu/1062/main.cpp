#include <iostream>
using namespace std;

char a[1000];int top=-1;

int main(){
    int t;
    cin>>t;
    cin.get();
    while(t--){
        char ch;
        top=-1;
        while(cin.get(ch)&&ch!='\n'){
            if(ch==32){
                for(int i=top;i>=0;i--){cout<<a[i];}cout<<" ";
                top=-1;
            }
            else{top++;a[top]=ch;}
        }
        
        for(int i=top;i>=0;i--){cout<<a[i];}cout<<endl;
        
    }
    
    return 0;
}
//end
//ism
