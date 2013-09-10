#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//#define _ISM_DEBUG_

int main (int args, char* argv[])
{
	if (args <= 2)
	{
		printf ("Wrong Command!\n");
		return 0;
	}
	string str_state = argv[1];
	if ("-c" == str_state && args == 4)
	{
		string str_folder = argv[2];
		string str_size  = argv[3];
		string str_command = 
			  "tar cvzpf - \"" 
			+ str_folder
			+ "\" | split -d -b " 
			+ str_size 
			+ " - "
			+ "\"" + str_folder
			+ ".tar.gz" + "\"";
#ifdef _ISM_DEBUG_
		// Debug Code if #define _ISM_DEBUG_
		cout << str_command << endl;
#endif
		system (&str_command[0]);
	}
	else if ("-x" == str_state && args == 3)
	{
		string str_folder = argv[2];
		string str_cat = "cat \"" + str_folder + "\"* > \"" + str_folder + "\"";
		string str_tar_gz = "tar -zxvf \"" + str_folder + "\"";
		string str_rm = "rm \"" + str_folder + "\"";
#ifdef _ISM_DEBUG_
		// Debug Code if #define _ISM_DEBUG_
		cout << str_cat << endl;
#endif
		system (&str_cat[0]);
#ifdef _ISM_DEBUG_
		// Debug Code if #define _ISM_DEBUG_
		cout << str_tar_gz << endl;
#endif
		system (&str_tar_gz[0]);
#ifdef _ISM_DEBUG_
		// Debug Code if #define _ISM_DEBUG_
		cout << str_rm << endl;
#endif
		system (&str_rm[0]);
	}
	return 0;
}


