#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int sum=0;
        if(n==1){sum=3;}
        else{
            sum=1;
            n++;
            while(n--){sum=sum*2;}
        };
        cout<<sum<<endl;
    }
    return 0;
}
//end
//ism
