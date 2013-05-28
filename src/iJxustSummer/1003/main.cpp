#include <string>
#include <iostream>
#include <fstream>
#include <string>

namespace ismdebug
{
    using namespace std;
    ifstream cin("in.dat",ios::in);
};

using ismdebug::cin;
//using std::cin;
using std::cout;
using std::endl;
using std::string;

int iA[7];
int iB[7];
int iC[7];

bool a_unknow[7];
bool b_unknow[7];
bool c_unknow[7];

int a_top;
int b_top;
int c_top;

int a_value, b_value, c_value;

int iSum;

void iCalA()
{
    int tmp = 0;
    for (int i = a_top; i >= 1; i--)
    {
        tmp *= 4;
        tmp += iA[i];
    }
}

void iCalB()
{
    int tmp = 0;
    for (int i = b_top; i >= 1; i--)
    {
        tmp *= 4;
        tmp += iB[i];
    }
}

void iCalC()
{
    int tmp = 0;
    for (int i = c_top; i >= 1; i--)
    {
        tmp *= 4;
        tmp += iC[i];
    }
}



void iJudge()
{
    iCalA();
    iCalB();
    iCalC();
    cout << a_value << " " << b_value << " " << c_value << endl;
    if (a_value + b_value == c_value)
    {
        iSum++;
    }
}

void iTry(int k)
{
    if (k > (a_top + b_top + c_top))
    {
        void iJudge();
        iJudge();
    }
    else
    {
        if (k <= a_top)
        {
            if (a_unknow[k])
            {
                for (int iNumberTemp = 0; iNumberTemp <= 3; iNumberTemp++)
                {
                    iA[k] = iNumberTemp;
                    iTry(k+1);
                }
            }
            else
            {
                iTry(k+1);
            }
        }
        else if (k <= (a_top + b_top))
        {
            if (b_unknow[k-a_top])
            {
                for (int iNumberTemp = 0; iNumberTemp <= 3; iNumberTemp++)
                {
                    iB[k-a_top] = iNumberTemp;
                    iTry(k+1);
                }
            }
            else
            {
                iTry(k+1);
            }
        }
        else if (k <= (a_top + b_top + c_top))
        {
            if (c_unknow[k-a_top-b_top])
            {
                for (int iNumberTemp = 0; iNumberTemp <= 3; iNumberTemp++)
                {
                    iC[k-a_top-b_top] = iNumberTemp;
                    iTry(k+1);
                }
            }
            else
            {
                iTry(k+1);
            }
        }
    }
}



int main()
{
    string s1, s2, s3;
    while (cin >> s1 >> s2 >> s3)
    {
        iSum  = 0;
        a_top = s1.length();
        b_top = s2.length();
        c_top = s3.length();

        // init for unknow[] of a , b, c
        for (int i = 0; i <= a_top; i++){a_unknow[i] = false;}
        for (int i = 0; i <= b_top; i++){b_unknow[i] = false;}
        for (int i = 0; i <= c_top; i++){c_unknow[i] = false;}
        //////////////////////////////////
        for (int i = 0; i < a_top; i++)
        {
            if (s1[i] == '?')
            {
                a_unknow[i+1] = true;
            }
            else
            {
                iA[i+1] = s1[i] - '0';
            }
        }

        for (int i = 0; i < b_top; i++)
        {
            if (s2[i] == '?')
            {
                b_unknow[i+1] = true;
            }
            else
            {
                iB[i+1] = s2[i] - '0';
            }
        }

        for (int i = 0; i < c_top; i++)
        {
            if (s3[i] == '?')
            {
                c_unknow[i+1] = true;
            }
            else
            {
                iC[i+1] = s3[i] - '0';
            }
        }

        iTry(1);

        cout << iSum << endl;
    }

    return 0;
}

// end
// ism
