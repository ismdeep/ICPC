/*
 * Project     : 6th
 * File        : main.cpp
 * Author      : iCoding
 *
 * Date & Time : Sat Oct 13 23:27:18 2012 
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <list>
#include <ctime>
#include <deque>
using namespace std;


char data[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

int main()
{
    int index[6];
    for (index[0] = 0; index[0] <= 1; index[0]++)
    {
	for (index[1] = 0; index[1] <= 1; index[1]++)
	{
	    for (index[2] = 0; index[2] <= 1; index[2]++)
	    {
		for (index[3] = 0; index[3] <= 1; index[3]++)
		{
		    for (index[4] = 0; index[4] <= 1; index[4]++)
		    {
			for (index[5] = 0; index[5] <= 1; index[5]++)
			{
			    // kernel of this program
			    // judge and output
			    // judge if there is nothing chose
			    bool is_nothing = true;
			    for (int k = 0; k < 6; k++)
			    {
				if (1 == index[k])
				{
				    is_nothing = false;
				}
			    }
			    // output if is_nothing == false;
			    if (false == is_nothing)
			    {
				for (int k = 0; k < 6; k++)
				{
				    if (index[k] == 1)
				    {
					cout << data[k] << " ";
				    }
				}
				cout << endl;
			    }
			    //
			}
		    }
		}
	    }
	}
    }
    return 0;
}

// end 
// iCoding@CodeLab
//

