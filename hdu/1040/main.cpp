#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++){cin>>a[i];}
        
        //еепР
        int flag;
        for(int i=0;i<n-1;i++){
            flag=i;
            for(int j=flag+1;j<n;j++){
                if(a[j]<a[flag]){
                    flag=j;
                }
            }
            int temp;
            temp=a[flag];a[flag]=a[i];a[i]=temp;
        }
        
        //output
        for(int i=0;i<n-1;i++){cout<<a[i]<<" ";}cout<<a[n-1]<<endl;
        
        
        delete[] a;
    }
    
    return 0;
}
//end
//ism
