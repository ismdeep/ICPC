#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstring>
using namespace std;

void clear_str_blank (string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
	if (str[i] == 32)
	{
	    str[i] = '-';
	}
    }
    str[str.length()-1] = '-';
}

string get_current_time ()
{
    time_t time_current;
    struct tm* time_info;
    time (&time_current);
    time_info = localtime (&time_current);
    string str_time_current = asctime (time_info);
    clear_str_blank (str_time_current);
    // cout << str_time_current << endl;
    char char_arr_time_info[100];
    for (int i = 0; i < 100; i++)
    {
	char_arr_time_info[i] = '\0';
    }
    char_arr_time_info[0]  = 'i';
    char_arr_time_info[1]  = 's';
    char_arr_time_info[2]  = 'm';
    char_arr_time_info[3]  = '_';
    char_arr_time_info[4]  = '2';
    char_arr_time_info[5]  = '0';
    char_arr_time_info[6]  = '1';
    char_arr_time_info[7]  = '2';
    char_arr_time_info[8]  = '-';
    char_arr_time_info[9]  = '1';
    char_arr_time_info[10] = '0';
    char_arr_time_info[11] = '-';
    char_arr_time_info[12] = str_time_current[8];
    char_arr_time_info[13] = str_time_current[9];
    char_arr_time_info[14] = '-';
    char_arr_time_info[15] = str_time_current[11];
    char_arr_time_info[16] = str_time_current[12];
    char_arr_time_info[17] = str_time_current[13];
    char_arr_time_info[18] = str_time_current[14];
    char_arr_time_info[19] = str_time_current[15];
    char_arr_time_info[20] = str_time_current[16];
    char_arr_time_info[21] = str_time_current[17];
    char_arr_time_info[22] = str_time_current[18];
    
    str_time_current = char_arr_time_info;
    cout << str_time_current << endl;
    return str_time_current;
}




int main ()
{
    string iStrInstruc;
    iStrInstruc = "scrot -s ~/ScrotScreenShot/" + get_current_time () + ".png";
    system (&iStrInstruc[0]);
    return 0;
}

// end
// iCoding
// @ CodeLab


