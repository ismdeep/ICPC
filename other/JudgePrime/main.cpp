#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num; /* give a number num which whill be judged if it is a prime */
    cin >> num; /* input a number to num */
    
    bool isPrime(int);
    
    if (isPrime(num)) /* judge num if it is a prime */
    {
        cout << num << " is a prime." << endl; 
    }
    else
    {
        cout << num << " is not a prime." << endl;
    }
    
    return 0;
    
}

/* judge function */
/* judge a number if it is a prime */
bool isPrime(int k)
{
    /* in order to make the program run more quickly, 
     * give a stop to cut it down when i got sqrt(k) 
     */
    int stop = (int)sqrt(k); 
   
    /* this value will be returned by "return yes;" */
    /* that stands if k is a prime */
    bool yes = true;
    
    /* frome 2 to sqrt(k), judge if there is an i,*/
    /* that k % i == 0, if exist such an i,*/
    /* k mustn't be a prime */
    for (int i = 2; yes && i <= stop; i++)
    {
        if (k % i == 0)
        {
            yes = false;
        }
        
    }
    
    return yes;
}

// end 
// ism

