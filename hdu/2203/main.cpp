#include <iostream>
using namespace std;

int main(){
    string str,s;
    while(cin>>str>>s){
        //cout<<"start!"<<endl;
        bool yes;
        yes=true;
        int top=0;
        while(yes&&s[top]!='\0'){
            bool found=false;
            for(int i=0;str[i]!='\0';i++){
                if(str[i]==s[top]){
                    found=true;
                }
            }
            if(!found){
                yes=false;
            }
            top++;
        }
        
        if(yes){cout<<"yes"<<endl;}
        else{cout<<"no"<<endl;}
        
        //cout<<"end!"<<endl;
    }
    return 0;
}
//end
//ism
