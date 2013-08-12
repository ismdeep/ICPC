//project name:2020 æ¯∂‘÷µ≈≈–Ú
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Fri Apr 13 13:32:49 2012

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n && n)
    {
        int *a = new int[n];
        
        //input numbers of a[]
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        for(int i =0; i < n-1; i++)
        {
            int flag;
            flag = i;
            for(int j = i+1; j < n; j++)
            {
                if(fabs(a[j]) > fabs(a[flag]))
                {
                    flag = j;
                }
            }
            
            //exchange values for a[i] and a[flag]:(max current)
            int intTemp;
            intTemp = a[i];
            a[i]    = a[flag];
            a[flag] = intTemp;
            
        }
        
        //output the last array of a[]
        for(int i = 0; i < n-1; i++)
        {
            cout<< a[i] <<" ";
        }
        cout<< a[n-1] << endl;
        
        
        //before exit this while loop , you should memory for araay a[]
        delete[] a;
    }
    return 0;
}
//end
//ism
