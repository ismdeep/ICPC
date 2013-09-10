#include <iostream>
using namespace std;

#define LENGTH 200000000
const bool PRIME    = true;
const bool NOTPRIME = false;

void ism()
{
    cout << "---ism!" << endl;
}

int main()
{
    int *a = new int[LENGTH];
    
    for (int i = 0; i < LENGTH; i++)
    {
        a[i] = PRIME;
    }
    
    int index = 2;
    
    while (index < LENGTH)
    {
        for (int i = index * index; i < LENGTH; i += index)
        {
            a[i] = NOTPRIME;
        }
        index++;
        while (a[index] != PRIME && index < LENGTH)
        {
            index++;
        }
        if (index >= 46340)
        {
            break;
        }
    }
    
    // output primes from 2 ~ LENGTH - 1 
    for (int i = 2; i < LENGTH; i++)
    {
        if (a[i] == PRIME)
        {
            cout << i << endl;
        }
    }
    
    delete[] a;
    return 0;
}

// end 
// ism 

