//project name:2028 Lowest Common Multiple Plus
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Sat Apr 14 16:06:25 2012

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        long long int a = 1;
        long long int b;
        while(n--)
        {
            cin >> b;
            long long int lcm(long long int, long long int);
            a = lcm(a,b);
        }
        
        //output the result
        cout<<a<<endl;
        
    }
    
    return 0;
}
///////////////////////////////////////////////////////////////////
long long int lcm(long long int p, long long int q)
{
    long long int gcd(long long int, long long int);
    return (p * q / gcd(p,q));
}
///////////////////////////////////////////////////////////////////
long long int gcd(long long int p, long long int q)
{
    if(p < q)
    {
        long long int temp;
        temp = p;
        p    = q;
        q    = temp;
    }
    
    while(q != 0)
    {
        long long int temp = p%q;
        p = q;
        q = temp;
    }
    
    return p;
}
//end
//ism
