/* 
 * Project Name : file_read_test
 * 
 * File Name : main.cpp
 * 
 * Author Name : namespace
 * 
 * Date & Time : Thu Nov 22 13:59:40 2012 
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

#include <fstream>
using namespace std; 

#define _ISM_DEBUG_ 

int main (int argc, char* argv[]) 
{
	if (argc != 3)
	{
		cout << "  -- Error! --" << endl;
		return 0;
	}
	char ch_in, ch_out;
	int n;
	//
	string infile_str = argv[1];
	string oufile_str = argv[2];
	//
	ifstream infile (&infile_str[0], ios::in);
	ofstream oufile (&oufile_str[0], ios::out);
	
	//
	while (infile.get(ch_in))
	{
		n = ch_in;
		if (n < 0)
		{
			n = 0 - n;
			n = 256 - n;
		}
		ch_out = n;
		oufile << ch_out;
	}
	return 0; 
} 
// end 
// namespace
// CodeLab
// 

