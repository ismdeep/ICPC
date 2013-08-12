#include <iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        a=a%10;
        b=b%4;
        b++;
        int sum=a;
        for(int i=0;i<=b+1;i++){
            sum=(sum*a)%10;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
//end
//ism
