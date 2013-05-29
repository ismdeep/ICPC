//Filename : StringToInt.h
#include <iostream>
using namespace std;

/***************long long int StringToInt(string s)*****************/
long long int StringToInt(string s)
{
    int point = 0;
	long long int _int_return = 0;
	while(s[point] != '\0')
	{
	    _int_return *= 10;
		_int_return += (s[point]-48);
		point++;
	}
	return _int_return;
}
/////////////////////////////////////////////////////////////////////
