#include <iostream>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        char charMax=str[0];
        int top=1;
        while(str[top]!='\0'){
            if(str[top]>charMax){charMax=str[top];}
            top++;
        }
        
        top=0;
        while(str[top]!='\0'){
            cout<<str[top];
            if(str[top]==charMax){cout<<"(max)";}
            top++;
        }
        cout<<endl;
    }
    return 0;
}
//end
//ism
