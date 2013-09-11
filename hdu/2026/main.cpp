#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    char ch;
    char pre,current;
    pre='\0';
    current='\0';
    while(cin.get(ch)){
        pre='\0';
        current='\0';
        pre=current;
        current=ch;
        if(pre=='\0'||pre==32){
            cout<<(char)(current-32);
        }
        else{cout<<current;}
        
        while(cin.get(ch)&&ch!='\n'){
            pre=current;current=ch;
            if(pre=='\0'||pre==32){
                cout<<(char)(current-32);
            }
            else{cout<<current;}
        }
        cout<<endl;
    }
    return 0;
}
//end
//ism
