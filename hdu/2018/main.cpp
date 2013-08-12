//project name:2018
//Author:键盘杀手

#include <iostream>
using namespace std;

long long int *a = new long long int[56];

void init()
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for(int i = 4; i < 56; i++)
    {
        a[i] = a[i-1] + a[i-3];
    }
}

int main()
{
    //初始化数据
    init();
    
    int n;
    
    while(cin >> n && n)
    {
        cout<< a[n] << endl;
    }
    
    delete[] a;
    return 0;
}
//end
//ism
