#include <iostream>
using namespace std;


typedef unsigned long long int longint;


class Buddy
{
private:
    char name[50];
    longint tel_num;
    char address[200];
public:
    Buddy();
    void setBuddy(const char*, longint, const char* );
    void printBuddy();
};

/*******************************************************************/

Buddy::Buddy()
{
    name[0]    = '\0';
    tel_num    = -1;
    address[0] = '\0';
}

void Buddy::setBuddy(
        const char* name, 
        longint tel_num, 
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
         << "Addr : " << this -> address << endl
         << endl;
}
