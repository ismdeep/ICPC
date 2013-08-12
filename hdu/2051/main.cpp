#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int a[3000];
        for(int i=0;i<3000;i++){a[i]=0;}
        int top=-1;
        while(n){
            top++;
            a[top]=n%2;
            n=n/2;
        }
        
        while(top){
            cout<<a[top--];
        }
        cout<<a[0];
        cout<<endl;
    }
}
//end
//ism
