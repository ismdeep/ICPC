// Project name : Defalut
// File name    : main.cpp
// Author       : iCoding
// Date & Time  :
// Email        : honi.linux@gmail.com

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

#define MAX_TRAIN_COUNT 15

bool iFlagNoProblem;

class Stack
{
    public:
    char* a;
    int iTop;
    Stack();
    void pop();
    void push(int iNum);
    char getTop();
};


Stack::Stack()
{
    a = new char[MAX_TRAIN_COUNT];
    iTop = -1;
    iFlagNoProblem = true;
}

void Stack::pop()
{
    if (iFlagNoProblem)
    {
        if (iTop == -1)
        {
            iFlagNoProblem = false;
            return;
        }
        else
        {
            iTop--;
            return ;
        }
    }
    else
    {
        return ;
    }
}

char Stack::getTop()
{
    if (iTop >= 0)
    {
        return a[iTop];
    }
    else
    {
        return '@';
    }
}

void Stack::push(int iNum)
{
    if (iFlagNoProblem)
    {
        iTop++;
        a[iTop] = iNum;
    }
    else
    {

    }
}


int n;
char iStrIn[MAX_TRAIN_COUNT];
char iStrOut[MAX_TRAIN_COUNT];

string iOperatorArr[MAX_TRAIN_COUNT * 2];
int iOperatorTop;

int iIndexStrIn;
int iIndexStrOut;

int main()
{
    //freopen("in.dat", "r", stdin);

    while (scanf("%d", &n) != EOF)
    {
        scanf("%s%s", iStrIn, iStrOut);

        Stack iStack;
        iOperatorTop = -1;
        iIndexStrOut = 0;
        for (iIndexStrIn = 0; iIndexStrIn < n; iIndexStrIn++)
        {
            iOperatorTop++;
            iOperatorArr[iOperatorTop] = "in";
            iStack.push(iStrIn[iIndexStrIn]);
            while (iStack.getTop() == iStrOut[iIndexStrOut])
            {
                iOperatorTop++;
                iOperatorArr[iOperatorTop] = "out";
                iStack.pop();
                iIndexStrOut++;
            }
        }

        if (iIndexStrOut != n)
        {
            iFlagNoProblem = false;
        }
        if (iFlagNoProblem)
        {
            cout << "Yes." << endl;
            for (int i = 0; i <= iOperatorTop; i++)
            {
                cout << iOperatorArr[i] << endl;
            }
            cout << "FINISH" << endl;
        }
        else
        {
            cout << "No." << endl;
            cout << "FINISH" << endl;
        }
    }

    return 0;
}

// end
// iCoding@CodeLab


