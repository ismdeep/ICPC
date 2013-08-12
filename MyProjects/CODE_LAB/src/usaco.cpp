#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iShowHelp()
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| use \"X:\\..\\..> usaco [project name]\" to create usaco project!      |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| Thank you for using this program!                                  |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| \t\t\t\t\tCreated by iCoding@CodeLab   |" << endl;	
	cout << "+--------------------------------------------------------------------+" << endl;
}

void iShowDoneMsg(string pro)
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| usaco prject \" "<< pro <<" \" Created successfully!!  ";
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

void iShowExistMsg(string pro)
{
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                                                                    |" << endl;
	cout << "| usaco project \" " << pro << " \" have existed already!";
	for (int i = 0; i <= (26 - pro.length()); i++)
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
int main(int args, char** argv)
{
	if (args <= 1)
	{
		iShowHelp();
		return 0;
	}
	string pro;
	pro = argv[1];
	if (pro == "-help" || pro == "--help" || pro == "?" || pro == "/?" || pro == "\\?")
	{
		iShowHelp();
		return 0;
	}
	//
	//
	//
	if (CheckFolderExist(pro))
	{
		//cout << "Exist Project!" << endl;
		iShowExistMsg(pro);
		return 0;
	}
	//
	//
	//
	string s_mkdir = "md " + pro;
	system(&s_mkdir[0]);
	//
	//
	string s_outmain = pro + "\\main.cpp";
	ofstream outmain(&s_outmain[0], ios::out);
	outmain << "/*" << endl;
	outmain << "ID: honi.li1" << endl;
	outmain << "PROG:" << pro << endl;
	outmain << "LANG: C++" << endl;
	outmain << "*/" << endl << endl;
	outmain << "#include <iostream>" << endl;
	outmain << "#include <stdio.h>" << endl;
	outmain << "#include <cmath>" << endl;
	outmain << "#include <algorithm>" << endl;
	outmain << "#include <map>" << endl;
	outmain << "#include <set>" << endl;
	outmain << "#include <list>" << endl;
	outmain << "#include <queue>" << endl;
	outmain << "#include <string>" << endl;
	outmain << endl;
	outmain << "namespace icoding" << endl;
	outmain << "{" << endl;
	outmain << "    using namespace std;" << endl;
	outmain << "    ifstream cin  ( \"" << pro << ".in"  << "\"" << ", ios::in  );" << endl;
	outmain << "    ofstream cout ( \"" << pro << ".out" << "\"" << ", ios::out );" << endl;
	outmain << "}" << endl;
	outmain << endl;
	outmain << "using icoding::cin;"  << endl;
	outmain << "using icoding::cout;" << endl;
	outmain << "using std::endl;"     << endl;
	outmain << "using std::string;"   << endl;
	outmain << endl;
	outmain << "int main()" << endl;
	outmain << "{" << endl;
	outmain << "    " << endl;
	outmain << "    return 0;" << endl;
	outmain << "}" << endl;
	outmain << "// end " << endl;
	outmain << "// iCoding@CodeLab" << endl;
	outmain << endl;
	//
	//
	string s_outmakefile = pro + "\\Makefile";
	ofstream outmakefile(&s_outmakefile[0], ios::out);
	outmakefile << "main:" << endl;
	outmakefile << "\tg++ main.cpp -o main" << endl;
	outmakefile << "\t" << endl;
	outmakefile << endl;
	//
	//
	//create pro input data file
	string s_infile = pro + "\\" + pro + ".in";
	ofstream out_in(&s_infile[0], ios::out);
	iShowDoneMsg(pro);
	//
	//
	//
	return 0;
}

// end 
// iCoding@CodeLab


