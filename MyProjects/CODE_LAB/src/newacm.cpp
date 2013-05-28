#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// global data
string author_name;
string home_path = "D:\\CODE_LAB\\com\\iCoding";
string company_name;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// debug function for debuging use
void debug()
{
	cout << "--debug msg--" << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// get current time information
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// show help msg if command wrong
void iShowHelp()
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| use \"X:\\..\\..> newacm [project name]\" to create usaco project!     |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| Thank you for using this program!                                  |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| \t\t\t\t\tCreated by iCoding@CodeLab   |" << endl;	
	cout << "+--------------------------------------------------------------------+" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// show done msg after project have been created
void iShowDoneMsg(string pro)
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| newacm prject \" "<< pro <<" \" Created successfully!! ";
	for (int i = 0; i <= (24 - pro.length()); i++)
	{
		cout << " ";
	}
	cout << "|"<< endl;
	cout << "|                                                                    |" << endl;
	cout << "| Thank you for using this program!                                  |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| \t\t\t\t\tCreated by iCoding@CodeLab   |" << endl;
	cout << "+--------------------------------------------------------------------+" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// show existing msg if there exist such project already
void iShowExistMsg(string pro)
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| newacm project \" " << pro << " \" have existed already!";
	for (int i = 0; i <= (25 - pro.length()); i++)
	{
		cout << " ";
	}
	cout << "|" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| Thank you for using this program!                                  |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| \t\t\t\t\tCreated by iCoding@CodeLab   |" << endl;
	cout << "+--------------------------------------------------------------------+" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// check folder exist by pro name
bool CheckFolderExist(string pro)
{
	WIN32_FIND_DATA wfd;
	bool rValue = false;
	HANDLE hFind = FindFirstFile(pro.c_str(), &wfd);
	if((hFind != INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		rValue = true;
	}
	FindClose(hFind);
	return rValue;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// get author's name
void get_author_name()
{
	string author_ini_path = home_path + "\\Author.ini";
	ifstream infile(&author_ini_path[0], ios::in);
	string str_tmp;
	while (infile >> str_tmp && str_tmp != "Author")
	{}
	infile >> str_tmp;
	if (str_tmp == "=")
	{
		infile >> author_name;
	}
	else
	{
		author_name = "iCoding";
	}
	//cout << author_ini_path << endl;
	//cout << author_name     << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// get company's name
void get_company_name()
{
	string company_name_path = home_path + "\\Author.ini";
	ifstream infile(&company_name_path[0], ios::in);
	string str_tmp;
	while (infile >> str_tmp && str_tmp != "lab")
	{}
	infile >> str_tmp;
	if (str_tmp == "=")
	{
		infile >> company_name;
	}
	else
	{
		company_name = "CodeLab";
	}
	cout << company_name_path << endl;
	cout << company_name      << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wriete msg to source file 
void write_source_file_msg(string pro)
{
	string infile_path;
	string oufile_path;
	// set path value
	infile_path = home_path + "\\main.cpp";
	oufile_path = pro       + "\\main.cpp";
	//
	//
	//
	//
	ifstream infile (&infile_path[0], ios::in);
	ofstream oufile (&oufile_path[0], ios::app);
	//
	//
	//
	char ch;
	while (infile.get(ch))
	{
		// debug();
		// cout << ch;
		if (ch == '~')
		{
			char c, o, d, e;
			infile.get(c);
			infile.get(o);
			infile.get(d);
			infile.get(e);
			if (c == 'C' && o == 'O' && d == 'D' && e == 'E')
			{
				string instruc;
				infile >> instruc;
				if (instruc == "<ProjectName>")
				{
					// output project name
					oufile << pro;
				}
				else if (instruc == "<FileName>")
				{
					// output file name
					oufile << "main.cpp";
				}
				else if (instruc == "<AuthorName>")
				{
					// output author's name
					get_author_name();
					oufile << author_name ;
				}
				else if (instruc == "<DateAndTime>")
				{
					// output date and time
					oufile << get_current_time();
				}
				else if (instruc == "<LabName>")
				{
					get_company_name();
					oufile << company_name;
				}
				else
				{
					oufile << instruc;
				}
			}
			else
			{
				oufile << "~" << c << o << d << e;
			}
		}
		else
		{
			oufile << ch;
		}
	}
	//
	// close files
	infile.close();
	oufile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// create folder for project
void create_folder(string pro)
{
	string cmd = "mkdir " + pro;
	system(&cmd[0]);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// write Makefile
void write_makefile(string pro)
{
	string infile_path;
	string oufile_path;
	// set path value
	infile_path = home_path + "\\Makefile";
	oufile_path = pro       + "\\Makefile";
	//
	//
	//
	//
	ifstream infile (&infile_path[0], ios::in);
	ofstream oufile (&oufile_path[0], ios::app);
	//
	//
	//
	char ch;
	while (infile.get(ch))
	{
		// debug();
		// cout << ch;
		oufile << ch;
	}
	// close file
	infile.close();
	oufile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void create_in_dat_file(string pro)
{
	string infile_path;
	infile_path = pro + "\\in.dat";
	ofstream oufile(&infile_path[0], ios::app);
	oufile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int args, char** argv)
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// init for program
	if (args == 1)
	{
		iShowHelp();
		return 0;
	}
	string pro = argv[1];
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// check project existing
	if (CheckFolderExist(pro) == true)
	{
		iShowExistMsg(pro);
		return 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// create folder for project
	create_folder(pro);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// create main.cpp file for project as the main source file and wirte preFileMsg into it 
	write_source_file_msg(pro);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// create Makefile for project and write preFileMsg into Makefile
	write_makefile(pro);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// create in.dat for project
	create_in_dat_file(pro);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	// show done msg 
	iShowDoneMsg(pro);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}

// end 
// iCoding@CodeLab


