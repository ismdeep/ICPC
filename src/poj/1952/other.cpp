#include<iostream>
using namespace std;

int a[5001];
int dp[5001];
int c[5001];

int main()
{
    int n;
    int i,j;
    int m=0;
    int sum=0;


    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i]=1;
        c[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            
            if(a[j]>a[i])
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    c[i]=c[j];
                }
                else if(dp[j]+1==dp[i])
                {
                    c[i]+=c[j];
                }
            }
            else if(a[j]==a[i])
            {
                if(dp[i]==1)
                    c[i]=0;
                break;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(m<dp[i])
            m=dp[i];
    }
    for(i=0;i<n;i++)
    {
        if(dp[i]==m)
            sum+=c[i];
    }
    cout<<m<<" "<<sum<<endl;
}


