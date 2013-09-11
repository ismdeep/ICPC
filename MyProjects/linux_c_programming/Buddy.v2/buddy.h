#ifndef BUDDY_H
#define BUDDY_H

typedef unsigned long long int longint;

class Buddy
{
private:
    char name[20];
    longint tel_num;
    char address[200];
public:
    Buddy();
    void setBuddy(const char*, longint, const char*);
    void printBuddy();
};

#endif
