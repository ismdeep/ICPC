#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

int main(int args,char **argv)
{
    
	if( args <= 2)
	{
	    //wrong input
		cout << "Wrong Input!" << endl;
		return 0;
	}
	string s = argv[1];
	if( s == "c" || s == "C" )
	{
	    //c ÓïÑÔÎÄŒþ
		
		string str = argv[2];
		
		str = str + ".c";
		
		ofstream outfile(&str[0],ios::app);
		
		outfile << "//File name:" << str << endl;
		outfile << "//Author:键盘杀手" << endl;
		outfile<<"//Creat Date & Time:";
		//output the time
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		outfile<<asctime(timeinfo);
		
		outfile<<endl;
		
		
		outfile << "#include <stdio.h>" << endl;
		outfile << endl << "int main()" << endl;
		outfile << "{" << endl;
		outfile << "    " << endl;
		outfile << "    return 0;" << endl;
		outfile << "}" << endl;
		outfile << "//end" << endl;
		outfile << "//ism" << endl;
		
		outfile.close();
		
	}
	
	else if( s == "cpp" || s == "CPP" )
	{
	    //cpp language files
		string str = argv[2];
		
		str = str + ".cpp";
		
		ofstream outfile(&str[0],ios::app);
		
		outfile << "//File name:" << str << endl;
		outfile << "//Author:ŒüÅÌÉ±ÊÖ" << endl;
		outfile<<"//Creat Date & Time:";
		//output the time
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		outfile<<asctime(timeinfo);
		
		outfile<<endl;
		
		
		outfile << "#include <iostream>" << endl;
		outfile << "using namespace std;" << endl;
		outfile << endl << "int main()" << endl;
		outfile << "{" << endl;
		outfile << "    " << endl;
		outfile << "    return 0;" << endl;
		outfile << "}" << endl;
		outfile << "//end" << endl;
		outfile << "//ism" << endl;
		
		outfile.close();
	}
	
	else if( s == "java" || s == "JAVA" )
	{
	    //java language files
		
		string str = argv[2];
		
		str += ".java";
		
		ofstream outfile(&str[0],ios::app);
		
		outfile << "public class " << argv[2] << endl;
		outfile << "{" << endl;
		outfile << "    public static void main(String[] argv)" << endl;
		outfile << "    {" << endl;
		outfile << "    }" << endl;
		outfile << "}" << endl;
		
		outfile.close();
		
	}
	
	else if( s == "null" || s == "NULL" )
	{
	    // null files
		string str = argv[2];
		
		ofstream outfile(&str[0],ios::app);
		outfile.close();
		
	}
	
	else
	{
	    //other type files
		string str;
		str = argv[2];
		str += ".";
		str += (string)argv[1];
		ofstream outfile(&str[0],ios::app);
		outfile.close();
		
	}
	
	return 0;
}
//end
//ism

