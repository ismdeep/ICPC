#include <iostream>
#include <fstream>
#include <ctime>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
using namespace std;

// #define _ISM_DEBUG_

// 来堆全局变量
int i_argc;
string i_argv[100];

string author_name;
string project_name;
string project_folder_path;
string lab_name;
string oj_name;
string problem_name;
string file_name;

///////////////////////////////////////////////////////////
// get current time information
// done
string get_current_time()
{
	time_t time_current;
	struct tm* time_info;
	time(&time_current);
	time_info = localtime(&time_current);
	string str_time_current = asctime(time_info);
	str_time_current[str_time_current.length() - 1] = 32;
	return str_time_current;
}

///////////////////////////////////////////////////////////
// just for debuging
void ism_debug ()
{
	cout << "-- debug --" << endl;
}

///////////////////////////////////////////////////////////
// just for debuging
// done
void show_i_argument ()
{
	cout << i_argc << endl;
	for (int i = 0; i < i_argc; i++)
	{
		cout << i_argv[i] << " ";
	}
	cout << endl;
}
    
void set_i_argument ()
{
    // doing nothing hr
}

void show_project_create_done_msg (string str_project_name)
{
	cout << "  Project \"" 
	     << str_project_name 
		 << "\" has been created successfully." 
		 << endl;
}

void show_help_msg ()
{
	cout << "  using $ newacm project_name [-oj oj_name] [-name problem_name] to create your acm project." << endl;
}

string get_out_makefile_path ()
{
	string out_makefile_path;
	out_makefile_path = project_name + "/Makefile";
	return out_makefile_path;
}
///////////////////////////////////////////////////////////
// get_author_name ();
// done
string get_author_name ()
{
	ifstream author_name_in (
			"/usr/share/newacm/ini/author",
			ios::in
			);
	string str;
	while (author_name_in >> str)
	{
		if ("author" == str)
		{
			author_name_in >> str;
			author_name_in >> str;
			author_name_in.close ();
			return str;
		}
	}
}

///////////////////////////////////////////////////////////
// get_project_name ();
// done
string get_project_name ()
{
	string str = i_argv[1];
	return str;
}

///////////////////////////////////////////////////////////
// get_project_folder_path ();
// done
string get_project_folder_path ()
{
	project_folder_path = project_name;
	bool has_problem_name = false;
	for (int i = 0; i < i_argc; i++)
	{
		if ("-name" == i_argv[i])
		{
			has_problem_name = true;
		}
	}
	if (has_problem_name)
	{
		project_folder_path += " - ";
		project_folder_path += problem_name;
	}
	return project_folder_path;
}


///////////////////////////////////////////////////////////
// get_lab_name ();
// done
string get_lab_name ()
{
	ifstream lab_name_in (
			"/usr/share/newacm/ini/author",
			ios::in
			);
	string str;
	while (lab_name_in >> str)
	{
		if ("lab" == str)
		{
			lab_name_in >> str;
			lab_name_in >> str;
			lab_name_in.close ();
			return str;
		}
	}
}


///////////////////////////////////////////////////////////
// get_oj_name ();
// done
string get_oj_name ()
{
	bool found = false;
	for (int i = 0; !found && i < i_argc; i++)
	{
		if ("-oj" == i_argv[i])
		{
			oj_name = i_argv[i+1];
			found = true;
		}
	}
	if (found)
	{
		return oj_name;
	}
	else
	{
		return "default";
	}
}


///////////////////////////////////////////////////////////
// get_problem_name ();
// done
string get_problem_name ()
{
	bool found = false;
	string str;
	for (int i = 0; !found && i < i_argc; i++)
	{
		if ("-name" == i_argv[i])
		{
			found = true;
			for (int j = i + 1; j < i_argc; j++)
			{
				if (j != i + 1)
				{
					str += " ";
				}
				str += i_argv[j];
			}
		}
	}
	return str;
}

///////////////////////////////////////////////////////////
// get_file_name ();
// done
string get_file_name ()
{
	string str_tmp;
	str_tmp = "main_" + oj_name + ".cpp";
	return str_tmp;
}
///////////////////////////////////////////////////////////
// create_project_folder ();
// done
void create_project_folder ()
{
	mkdir (&project_folder_path[0], -1);
}

///////////////////////////////////////////////////////////
// get_main_cpp_resource_path ();
string get_main_cpp_resource_path ()
{
	string str_tmp;
	str_tmp = "/usr/share/newacm/resource/" + file_name;
	return str_tmp;
}

///////////////////////////////////////////////////////////
// translator ()
string translator (string str)
{
	string str_return;
	if ("<p>" == str)
	{
		str_return = "\n";
	}
	else if ("[project_name]" == str)
	{
		str_return = project_name;
	}
	else if ("[author_name]" == str)
	{
		str_return = author_name;
	}
	else if ("[lab_name]" == str)
	{
		str_return = lab_name;
	}
	else if ("[date_and_time]" == str)
	{
		str_return = get_current_time();
	}
	else if ("[file_name]" == str)
	{
		str_return = file_name;
	}
	else if ("[tab]" == str)
	{
		str_return = "\t";
	}
	else if ("[blank]" == str)
	{
		str_return = " ";
	}
	else
	{
		str_return = str;
	}
	return str_return;
}
///////////////////////////////////////////////////////////
// write_msg_main_cpp ();
// done
void write_msg_main_cpp ()
{
	string main_cpp_path;
	string main_cpp_resource_path;
	main_cpp_resource_path = get_main_cpp_resource_path ();
	main_cpp_path = project_folder_path + "/main.cpp";
	ifstream main_cpp_in (
			&main_cpp_resource_path[0],
			ios::in
			);
	ofstream main_cpp_ou (
			&main_cpp_path[0],
			ios::app
			);
	string str;
	while (main_cpp_in >> str)
	{
		if ("[code]" == str)
		{
			main_cpp_in >> str;
			str = translator (str);
			main_cpp_ou << str;
		}
		else
		{
			main_cpp_ou << str << " ";
		}
	}
	main_cpp_in.close ();
	main_cpp_ou.close ();
}

///////////////////////////////////////////////////////////
// write_msg_Makefile ();
// done
void write_msg_Makefile ()
{
	// set in stream of resource file : Makefile
	ifstream makefile_in (
			"/usr/share/newacm/resource/Makefile",
			ios::in
			);
	// set out_makefile_path;
	string out_makefile_path;
	out_makefile_path = project_folder_path + "/Makefile";
	// set out stream to file : out_makefile_path
	ofstream makefile_ou (
			&out_makefile_path[0],
			ios::app
			);
	char ch;
	while (makefile_in.get (ch))
	{
		makefile_ou << ch;
	}
	// close file stream of makefile in and out
	makefile_in.close ();
	makefile_ou.close ();
}

void write_msg_in_dat ()
{
	// set out_in_dat_path;
	string out_in_dat_path;
	out_in_dat_path = project_folder_path + "/in.dat";
	// set out stream to file : out_in_dat_path
	ofstream in_dat_ou (
			&out_in_dat_path[0],
			ios::out
			);
	// close file stream of in.dat in and out
	in_dat_ou.close ();
}

int main (int argc, char* argv[])
{
	// set_i_argument ()
	// but that will doing in down 
	// set_i_argument () not in set_i_argument ();
	set_i_argument ();
	i_argc = argc;
	for (int i = 0; i < i_argc; i++)
	{
		i_argv[i] = argv[i];
	}
	//show_i_argument ();
	///////////////////////////////////////////////////////
	if (argc <= 1)
	{
		show_help_msg ();
		return 0;
	}
	///////////////////////////////////////////////////////
	// get name of author project lab oj problem
	author_name         = get_author_name         ();
	project_name        = get_project_name        ();
	problem_name        = get_problem_name        ();
	project_folder_path = get_project_folder_path ();
	lab_name            = get_lab_name            ();
	oj_name             = get_oj_name             ();
	file_name           = get_file_name           ();
#ifdef _ISM_DEBUG_
	cout << "Date & Time -> " 
		 << get_current_time () << endl;
	cout << "author  = " << author_name  << endl
		 << "project = " << project_name << endl
		 << "lab     = " << lab_name     << endl
		 << "oj      = " << oj_name      << endl
		 << "problem = " << problem_name << endl
		 << "path    = " << project_folder_path << endl
		 << "file    = " << file_name << endl;
#endif
	///////////////////////////////////////////////////////
	create_project_folder ();
	write_msg_main_cpp    ();
	write_msg_Makefile    ();
	write_msg_in_dat      ();
	show_project_create_done_msg (project_name);
	///////////////////////////////////////////////////////
	return 0;
}
// end
// ismdeep
// CodeLab
// www.ism.name

