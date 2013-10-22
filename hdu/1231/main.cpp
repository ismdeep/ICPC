#include <iostream>
#include <stdio.h>
using namespace std;

class node{
public:
int number;
int sum;
int begin;
int end;
};

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        node *a=new node[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].number);
        }
        
        a[0].sum=a[0].number;
        a[0].begin=0;
        a[0].end=0;
        int flag=0;
        for(int i=1;i<n;i++){
            if(a[i-1].sum<0){
                a[i].sum=a[i].number;
                a[i].begin=i;
                a[i].end=i;
            }
            else{
                if(a[i-1].sum+a[i].number<0){
                    a[i].sum=a[i].number;
                    a[i].begin=i;
                    a[i].end=i;
                }
                else{
                    a[i].sum=a[i].number+a[i-1].sum;
                    a[i].begin=a[i-1].begin;
                    a[i].end=i;
                }
            }
            if(a[flag].sum<a[i].sum){
                flag=i;
            }
        }
        
        if(a[flag].sum<0){
            cout<<0<<" "<<a[0].number<<" "<<a[n-1].number<<endl;
        }
        else{
            cout<<a[flag].sum<<" "<<a[a[flag].begin].number<<" "<<a[a[flag].end].number<<endl;
        }
        
        
    }
    return 0;
}
//end
//ism
