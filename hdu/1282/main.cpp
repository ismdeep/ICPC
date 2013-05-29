#include <iostream>
using namespace std;
void ism(){cout<<"ism"<<endl;}
bool isHuiwenshu(int k){
    int a[100];
    for(int i=0;i<100;i++){a[i]=0;}
    
    int current=-1;
    while(k){
        a[++current]=k%10;
        k/=10;
    }
    
    int flag;
    flag=99;
    while(a[flag]==0){flag--;}
    
    bool flagflag=true;
    for(int i=0;i<=(flag/2);i++){
        if(a[i]!=a[flag-i]){flagflag=false;break;}
    }
    
    return flagflag;
}

int cal(int k){
    int a[100];
    for(int i=0;i<100;i++){a[i]=0;}
    
    int current=-1;
    while(k){
        a[++current]=k%10;
        k/=10;
    }
    
    int flag;
    flag=99;
    while(a[flag]==0){flag--;}
    
    int temp=0;
    
    int fac10(int);
    for(int i=0;i<=flag;i++){
        temp+=a[i]*(fac10(i)+fac10(flag-i));
    }
    
    
    //test 
    //cout<<temp<<endl;
    
    return temp;
}

int fac10(int k){
    int temp=1;
    for(int i=0;i<k;i++){
        temp=temp*10;
    }
    
    return temp;
}
int main(){
    int start;
    while(cin>>start){
        int route[1000];
        int top=-1;
        route[++top]=start;
        if(isHuiwenshu(start)){
            cout<<"0"<<endl<<start<<endl;
        }
        else{
            while(!isHuiwenshu(route[top])){
                route[top+1]=cal(route[top]);
                top++;
            }
            
            //¿ªÊ¼Êä³ö
            cout<<top<<endl;
            for(int i=0;i<top;i++){
                cout<<route[i]<<"--->";
            }
            cout<<route[top]<<endl;
        }
    }
    
    return 0;
}
//end
//ism
