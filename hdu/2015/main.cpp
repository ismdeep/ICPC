#include <iostream>
using namespace std;

int n,m;

int main(){
    while(cin>>n>>m){
        void work();
        work();
    }
    return 0;
}
/////////////////////////////////////////////
void work(){
    int count=0;
    int *a=new int[n+1];
    //初始化a[]
    for(int i=0;i<=n;i++){a[i]=0;}
    for(int i=1;i<=n;i++){a[i]=2*i;}
    
    int time=n/m;
    int lastTime=n%m;
    
    //正常输出
    for(int i=0;i<time;i++){
        int sum=0;
        for(int j=i*m+1;j<=(i+1)*m;j++){
            sum+=a[j];
        }
        if(count){cout<<" ";}count++;
        cout<<sum/m;
    }
    
    //剩余输出
    if(lastTime){
        int sum=0;
        for(int i=time*m+1;i<=n;i++){
            sum+=a[i];
        }
        if(count){cout<<" ";}count++;
        cout<<sum/lastTime;
    }
    
    cout<<endl;
    
    delete[] a;
}
//end;
