#include <iostream>
#include <string.h>
#include "buddy.h"
using std::cout;
using std::endl;

Buddy::Buddy()
{
    this -> name[0]    = '\0';
    this -> tel_num    =  -1 ;
    this -> address[0] = '\0';
}

void Buddy::setBuddy(
        const char* name,
        const longint tel_num,
        const char* address
        )
{
    strcpy(this -> name   , name   );
    this -> tel_num = tel_num;
    strcpy(this -> address, address);
}

void Buddy::printBuddy()
{
    cout << "Name : " << this -> name    << endl
         << "Tel  : " << this -> tel_num << endl
         << "Addr : " << this -> address << endl;
}



