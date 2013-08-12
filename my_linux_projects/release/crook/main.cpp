/* 
 * Project Name : crook
 * 
 * File Name    : main.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Wed Nov 28 16:44:11 2012 
 * 
 * */ 
#include <set> 
#include <map> 
#include <list> 
#include <cmath> 
#include <ctime> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <cctype> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <cassert> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 
#include <iostream> 
#include <algorithm> 

using namespace std; 

// #define _ISM_DEBUG_ 

int main (int argc, char* argv[])
{
	if (argc <= 1)
	{
		cout << " Error!" << endl;
		return 0;
	}
	//------------------------------------------------------------------------------//
		string str_file_name;
		str_file_name += "\"";
		for (int i = 1; i < argc; i++)
		{
			if (1 != i)
			{
				str_file_name += " ";
			}
			str_file_name += argv[i];
		}
		str_file_name += "\"";
		string str_en_instruc;
		str_en_instruc = "bcrypt " + str_file_name + " < /etc/crook/key.en";
#ifdef _ISM_DEBUG_
		cout << str_en_instruc << endl;
#endif
		system (&str_en_instruc[0]);
	//------------------------------------------------------------------------------//
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

