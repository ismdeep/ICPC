#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n&&n){
        long int timeTotal=0;
        int pre=0;
        int current;
        while(n--){
            cin>>current;
            if(current>pre){
                timeTotal+=((current-pre)*6+5);
            }
            if(current<pre){
                timeTotal+=((pre-current)*4+5);
            }
            if(current==pre){
                timeTotal+=5;
            }
            pre=current;
        }
        
        cout<<timeTotal<<endl;
        
    }
    return 0;
}
//end
//ism
