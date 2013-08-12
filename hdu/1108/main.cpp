#include <iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        int temp;
        int mul=a*b;
        if(a<b){temp=a;a=b;b=temp;}
        
        while(b){
            temp=a%b;
            a=b;b=temp;
        }
        cout<<mul/a<<endl;
    }
    return 0;
}
//end
//ism
