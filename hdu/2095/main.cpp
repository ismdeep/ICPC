//project name:2095 ( find your present (2) )
//Author:º¸≈Ã…± ÷
//Creat Date & Time:Fri Apr 27 15:28:50 2012

#include <iostream>
#include <stdio.h>
using namespace std;

class Node
{
public:
    int num;
	int count;
};

int main()
{
    int n;
	
	while( scanf("%d",&n)!=EOF && n)
	{
	    Node *a = new Node[n];
		
		// start 
		
		int top = -1;
		for(int i = 0; i < n; i++)
		{
		    int num;
			//cin >> num;
			scanf("%d",&num);
			bool found = false;
			
			for(int j = 0; !found && j <= top; j++)
			{
			    if( a[j].num == num)
				{
				    a[j].count++;
					found = true;
				}
			}
			
			if( !found )
			{
			    top++;
				a[top].num = num;
				a[top].count = 1;
			}
			
		}
		
		// find the only one 
		for(int i = 0; i <= top; i++)
		{
		    if(a[i].count == 1)
			{
			    cout << a[i].num << endl;
			}
			
		}
		
		delete[] a;
	}
	
    return 0;
}
//end
//ism
