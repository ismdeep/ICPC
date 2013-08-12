#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int max;
        int n;
        long long int sum=0;
        int i,temp;
        
        scanf("%d",&n);
        scanf("%d",&max);
        sum+=max;
        
        for(i=1;i<n;i++){
            scanf("%d",&temp);
            sum+=temp;
            if(temp>max){max=temp;}
        }
        
        
        sum=sum-max;
        
        if(max>=sum+2){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
        
    }
    return 0;
}
//end
//ism
