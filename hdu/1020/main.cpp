#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int flag=0;
        while(str[flag]!='\0'){flag++;}
        flag;
        
        char ch=str[0];int count=1;
        int current=0;
        do{
            current++;
            if(str[current]!=ch){
                if(count!=1){cout<<count;}
                
                cout<<ch;
                ch=str[current];
                count=1;
                
            }
            else{
                count++;
            }
        }while(str[current]!='\0');
        
        cout<<endl;
    }
    return 0;
}
//end
//ism
