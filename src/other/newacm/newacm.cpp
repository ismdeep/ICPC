// Project name : New ACM
// File name    : newacm.cpp
// Author       : Izumu
// Data & Time  : 2012-06-21 11:26

#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <fstream>
using namespace std;

int main(int args, char** argv)
{
    if (args <= 1)
    {
        cout << "Error Input!" << endl;
        return 0;
    }

    // mkdir 
    string dir;
    dir = argv[1];
    mkdir(&dir[0], -1);

    // create file
    string file_path = dir + "/main.cpp";
    ofstream outfile (&file_path[0], ios::app);
    
    outfile << "// Project name : " << dir ;
    if (args > 2)
    {
        outfile << " ( " ;
        for (int i = 2; i < args; i++)
        {
            string str_temp;
            str_temp = argv[i];
            outfile << str_temp << " ";
        }
        outfile << ") ";
    }
    outfile << endl;
    outfile << "// File name    : " << "main.cpp" << endl;
    outfile << "// Author       : " << "Izumu" << endl;
    outfile << "// Date & Time  : " ;
    /* output current time */
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    outfile << asctime(timeinfo) << endl << endl;
    /* finish output current time */

    outfile << "#include <iostream>" << endl;
    outfile << "using namespace std;" << endl;
    outfile << endl;
    outfile << "int main()" << endl;
    outfile << "{" << endl;
    outfile << "    " << endl;
    outfile << "    return 0;" << endl;
    outfile << "}" << endl;
    outfile << endl;
    outfile << "// end " << endl;
    outfile << "// ism " << endl;
    outfile << endl;


    outfile.close();

    return 0;
}

// end 
// ism 
