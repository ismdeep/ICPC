//project name:1405 ( The Last Practice )
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Sat Apr 28 21:58:42 2012

#include <iostream>
#include <cmath>
using namespace std;
/*****************/
class Node
{
public:
    int num;
	int count;
};

int primeArr[6600];

int main()
{
    void task(int);
	void primeArrInit();
	primeArrInit();
	int n;
	int t = 1;
	while( cin >> n && n != -1 )
	{
	    cout << "Case " << t++ << "." << endl;
		task(n);
		cout << endl;
	}
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
bool isPrime(int k)
{
    bool yes = true;
	int stop = sqrt(k);
	for(int i = 2; yes && i <= stop; i++)
	{
	    if( k % i == 0)
		{
		    yes = false;
		}
	}
	
	return yes;
}
//////////////////////////////////////////////////////////////////////////////
void primeArrInit()
{
	int topPrimeArr = -1;
	for(int i = 2; i < 65536; i++ )
	{
	    if(isPrime(i))
		{
		    topPrimeArr++;
			primeArr[topPrimeArr] = i;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
int nextPrime(int index)
{
    return primeArr[index+1];
}
//////////////////////////////////////////////////////////////////////////////
void task(int k)
{
    int currentIndex = 0;
	Node *a = new Node[100];
	//cout << "ism" << endl;
	int top = -1;
	
	while( k != 1)
	{
	    if( k % primeArr[currentIndex] == 0 )
		{
		    if( top == -1 || a[top].num != primeArr[currentIndex] )
			{
			    top++;
				a[top].num = primeArr[currentIndex];
				a[top].count = 1;
			}
			else
			{
			    a[top].count += 1;
			}
			k = k / primeArr[currentIndex];
			
			if( k != 1 && isPrime(k) )
			{
			    if( a[top].num == k )
				{
				    a[top].count++;
				}
				else
				{
				    top++;
					a[top].num = k;
					a[top].count = 1;
				}
				
				k = 1;
			}
			
		}
		else
		{
		    currentIndex++;
		}
	}
	
	// print result
	for(int i = 0; i <= top; i++ )
	{
	    cout << a[i].num << " " << a[i].count << " ";
	}
	cout << endl;
	
}
//end
//ism
