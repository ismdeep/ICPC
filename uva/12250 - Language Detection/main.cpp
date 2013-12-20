/* 
 * Project Name : 12250
 * 
 * File Name : main_default.cpp
 * 
 * Author Name : ismdeep
 * 
 * Date & Time : Fri Dec 20 19:25:32 2013 
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

#define _ISM_DEBUG_ 

map<string,string> shit;

void init_shit ()
{
	shit["HELLO"] = "ENGLISH";
	shit["HOLA"] = "SPANISH";
	shit["HALLO"] ="GERMAN";
	shit["BONJOUR"] ="FRENCH";
	shit["CIAO"] ="ITALIAN";
	shit["ZDRAVSTVUJTE"] ="RUSSIAN";
}

int main () 
{
	init_shit ();
	string str;
	int case_index = 0;
	while (cin >> str, str[0] != '#')
	{
		case_index++;
		cout << "Case " << case_index << ": ";
		if ("HELLO" == str ||
			"HOLA" == str ||
			"HALLO" == str ||
			"BONJOUR" == str ||
			"CIAO" == str ||
			"ZDRAVSTVUJTE" == str)
		{
			cout << shit[str] << endl;
		}
		else
		{
			cout << "UNKNOWN" << endl;
		}
	}
	return 0; 
} 
// end 
// ismdeep
// xTarget
// 

