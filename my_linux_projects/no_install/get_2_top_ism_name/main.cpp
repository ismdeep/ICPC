#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main ()
{
	while (1)
	{
		system ("wget -b -q http://www.baidu.com/link?url=mXcXGJqjJ4zBBpC8yDF8xDh8vibi0ElgSmoCbI2O -O index.html");
		system ("rm index.html");
		sleep (2);
	}
	return 0;
}
