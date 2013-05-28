#include <iostream>
//#include <windows.h>
#include <fstream>
#include <time.h>
using namespace std;

int main(int args, char** argv)
{
    if(args == 1)
	{
	    return 0;
	}
	
	string str = argv[1];
	
	// judge if the project allready exist
	bool CheckFolderExist(string);
	if(0)
	{
	    cout<<"The project of: "<<str<<" allready exist!";
		return 0;
	}
	
	//make a dir for the newacm project
	string instru;
	instru = "md " + str;
	system(&instru[0]);
	
	//create a main.cpp in the project dir that create above
	instru = str + "\\main.cpp";
	ofstream outfile(&instru[0],ios::app);
	
	/////////////////////////////////////////////////////////////////////
	//start write the preProgramming information to str\\main.cpp
	outfile<<"//project name:"<<str;
	
	if(args >= 3)
	{
	    outfile<<" ( ";
		for(int i = 2; i < args; i++)
		{
		    outfile<<argv[i]<<" ";
		}
		outfile<<")";
	}
	outfile << endl;
	
	outfile<<"//Author:¼üÅÌÉ±ÊÖ"<<endl;
	outfile<<"//Creat Date & Time:";
	
	//output the time
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	outfile<<asctime(timeinfo);
	
	outfile<<endl;
	
	outfile<<"#include <iostream>"<<endl;
	outfile<<"using namespace std;"<<endl;
	outfile<<endl;
	outfile<<"int main()"<<endl;
	outfile<<"{"<<endl;
	outfile<<"    "<<endl;
	outfile<<"    "<<"return 0;"<<endl;
	outfile<<"}"<<endl;
	outfile<<"//end"<<endl<<"//ism"<<endl;
	
	outfile.close();
	
	return 0;
}

//end
//ism
