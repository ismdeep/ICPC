// project name : Friend Number
// file name : main.cpp
// author : keyboardKiller
// date & time : 2012 05 18 -> 14 : 32
// @ copyLeft


#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 5000000

bool tested[MAX];



int CDivisinSum(int k)
{
    int sum = 0;
    int stop = k / 2;
    for(int i = 1; i <= stop; i++)
    {
        if( k % i == 0 )
        {
            sum += i;
        }
    }
    
    return sum;
    
}


int main()
{
    ofstream outfile("friendNumber.dat",ios::out);
    
    // init for tested
    for(int i = 0; i < MAX; i++)
    {
        tested[i] = false;
    }
    
    for(int num = 1; num < MAX; num++)
    {
        cout << "\r" << num <<" ";
        printf("\t%.6f%%",(double)(num * 100)/5000000);
        
        
        if( !tested[num] )
        {
            int temp = CDivisinSum(num);
            if(temp >= num)
            {
                if( num == CDivisinSum(temp) )
                {
                    outfile << num << " " << temp << endl;
                }
            }
            tested[num] = true;
            tested[temp] = true;
        }
        
    }
    
    
    outfile.close();
    return 0;
}

// end
// ism

