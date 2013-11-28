#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


#ifndef SCAN_TIME_SLEEP
#define SCAN_TIME_SLEEP 300
#endif

int scan_time_sleep = 300;

// get_scan_time_sleep 
void get_scan_time_sleep ()
{
	ifstream infile ("sleep_time.dat", ios::in);
	infile >> scan_time_sleep;
	infile.close ();
}

string file_name = "index.html";
string url = "http://izone.sourceforge.net/wap/";

int main ()
{
	// get scan sleep time
	get_scan_time_sleep ();
	//
	bool do_shutdown = false;
	while (!do_shutdown)
	{
		string rm_instruc = "rm " + file_name;
		system (&rm_instruc[0]);
		//
		string getmsg_instruc = "curl " + url + " -o " + file_name;
		system (&getmsg_instruc[0]);
		//
		ifstream infile (&file_name[0], ios::in);
		string str;
		string last_instruc = "nothing";
		bool found = false;
		while (infile >> str && !found)
		{
			if ("iCodingShutdown=true" == str || "iCodingShutdown=false" == str)
			{
				last_instruc = str;
				found = true;
			}
		}
		// judge and shutdown
		if ("iCodingShutdown=true" == last_instruc)
		{
			system ("poweroff");
			do_shutdown = true;
		}
		infile.close ();
		//sleep (SCAN_TIME_SLEEP);
		sleep (scan_time_sleep);
	}
	return 0;
}

// end 
// iCoding
//

