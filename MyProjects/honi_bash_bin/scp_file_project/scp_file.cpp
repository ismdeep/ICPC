// iCoding
// Project 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

void show_help_msg ()
{
	cout << " -- using help -- " << endl;
	cout << "    scp_file [filenaem] [path]" << endl;
	cout << "    .. eg .. " << endl;
	cout << "    scp_file Ubuntu10.04.iso iso_files/Ubuntu" << endl;
}

int main (int argc, char* argv[])
{
	if (argc <= 2)
	{
		show_help_msg ();
		return 0;
	}
	string filename;
	filename = argv[1];
	string path = "honix@frs.sourceforge.net:/home/frs/project/honi/";
	path += argv[2];
	cout << path << endl;
	string upload_instruc;
	upload_instruc = "scp " + filename + " " + path;
	// start doing upload_instruc
	system (&upload_instruc[0]);
	return 0;
}
