#include <iostream>
#include <fstream>
#include "icoding_debug_head.h"
using namespace std;
using namespace icoding;

string str_pro_name;
string str_file_name;
string str_author_name;

void output_pro_name()
{
	cout << str_pro_name;
}

void output_file_name()
{
	cout << str_file_name;
}

void output_author_name()
{
	cout << str_author_name;
}
void output_date_and_time()
{
	/* debug only */
	cout << "-- debug -- 2012-08-17 Fri 20:01";
}

void init_name()
{
	ifstream in_name("D:\\CODE_LAB\\com\\iCoding\\Author.ini", ios::in);
	in_name >> str_author_name;
}

int main(int args, char** argv)
{
	// init for judge if input is leagal
	//
	if (args <= 1)
	{
		cout << "! Wrong Input" << endl;
		return 0;
	}
	//
	//
	// init for pro name 
	//
	str_pro_name  = argv[1];
	str_file_name = "main.cpp";
	//
	init_name();
	ifstream infile("D:\\CODE_LAB\\com\\iCoding\\cpp.ixml", ios::in);
	char ch;
	while (infile.get(ch))
	{
		if (ch == '~')
		{
			//debug_msg();
			string code;
			for (int i = 0; i < 4; i++)
			{
				infile.get(code[i]);
			}
			if (code == "CODE")
			{
				string instruc;
				infile >> instruc;
				if (instruc == "<ProjectName>")
				{
					/* output Project Name */
					output_pro_name();
				}
				if (instruc == "<FileName>")
				{
					/* output File Name */
					output_file_name();
				}
				if (instruc == "<Author>")
				{
					/* output Author's Name */
					output_author_name();
				}
				if (instruc == "<DateAndTime>")
				{
					/* output Date And Time */
					output_date_and_time();
				}
			}
		}
		cout << ch;
	}
	return 0;
}

// end 
// iCoding@CodeLab
//

