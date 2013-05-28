#include <iostream>
#include "StringToInt.h"
using namespace std;

int main(int args, char** argv)
{
    if(args == 1)
	{
	    return 0;
	}
	
	cout << StringToInt(argv[1]) << endl;
	
	return 0;
}
//end;
//ism
