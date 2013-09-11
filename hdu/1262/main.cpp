#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int k){
    int stop=sqrt(k);
    bool ok=true;
    for(int i=2;i<=stop;i++){
        if(k%i==0){
            ok=false;
            break;
        }
    }
    return ok;
}

void find(int k){
    int mid;
    mid=k/2;
    int current=mid;
    bool yes=false;
    while(!yes){
        if(isPrime(current)&&isPrime(k-current)){
            yes=true;
        }
        current--;
    }
    current++;
    
    cout<<current<<" "<<k-current<<endl;
}

int main(){
    int num;
    while(cin>>num){
        find(num);
    }
    return 0;
}
//end
//ism
